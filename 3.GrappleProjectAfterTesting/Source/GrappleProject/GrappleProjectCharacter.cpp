// Copyright Epic Games, Inc. All Rights Reserved.

#include "GrappleProjectCharacter.h"
#include "GrappleProjectProjectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "CableComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"


//////////////////////////////////////////////////////////////////////////
// AGrappleProjectCharacter

AGrappleProjectCharacter::AGrappleProjectCharacter()
{

	PrimaryActorTick.bCanEverTick = true;
	// Character doesnt have a rifle at start
	bHasRifle = false;
	
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

	//Create the cable used to visualise the grapple
	GrappleCable = CreateDefaultSubobject<UCableComponent>(TEXT("GrappleCable"));
	GrappleCable->SetupAttachment(FirstPersonCameraComponent);
	GrappleCable->SetVisibility(false); // Hide it by default

	// making materials for the cable
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> mCableMaterial(TEXT("/Game/Materials/M_CableMaterial"));
	static ConstructorHelpers::FObjectFinder<UMaterialInterface> mCableMaterialOOR(TEXT("/Game/Materials/M_CableMaterialOOR"));
	if (mCableMaterial.Succeeded()) CableMaterial = mCableMaterial.Object;
	if (mCableMaterialOOR.Succeeded()) CableMaterialOOR = mCableMaterialOOR.Object;
}

void AGrappleProjectCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

}

//////////////////////////////////////////////////////////////////////////// Input

void AGrappleProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{

	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(ResetPositionAction, ETriggerEvent::Triggered, this, &AGrappleProjectCharacter::ResetPosition);

		//Grappling(?) trying to keep commenting same as base
		EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Triggered, this, &AGrappleProjectCharacter::GrapplePressed);
		EnhancedInputComponent->BindAction(GrappleAction, ETriggerEvent::Completed, this, &AGrappleProjectCharacter::GrappleReleased);

		//Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGrappleProjectCharacter::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AGrappleProjectCharacter::Look);
	}
}


void AGrappleProjectCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();
	MoveInput = MovementVector;

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AGrappleProjectCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AGrappleProjectCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GrappleCooldown > 0.0f)
	{
		GrappleCooldown -= DeltaTime;
		if (GrappleCooldown <= 0.0f)
		{
			CanGrapple = true;
		}
	}

	if (IsGrappling)
	{

		FVector CurrentLocation = GetActorLocation();
		FVector GrappleLength = GrappleTarget - CurrentLocation;
		float Distance = GrappleLength.Size();
		FVector Direction = GrappleLength.GetSafeNormal();
		
		FVector ViewDirection = GetControlRotation().Vector();
		float DotProduct = FVector::DotProduct(ViewDirection, Direction);
		float PlayerAngle = FMath::RadiansToDegrees(FMath::Acos(DotProduct));

		GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(GrappleTarget);
		GrappleCable->SetMaterial(0, CableMaterial);
		//DrawDebugLine(GetWorld(), CurrentLocation, GrappleTarget, FColor::Turquoise, false, -1.0f, 0, 2.0f);

		//if the player looks too far away from the grapple point, or lets go of the button
		// detach the grapple and change appropriate variables
		if (PlayerAngle > 90.0f || !IsGrapplePressed)
		{
			GrappleReleased();
			//UE_LOG(LogTemp, Warning, TEXT("Grapple broken"));
			return;
		}

		// if the player gets too close, detach grapple
		if (Distance <= MinGrappleRange)
		{
			GrappleReleased();
			return;
		}

		if (shouldSwing) {

			// Creating gravity that will affect the player as they swing
			
			FVector Gravity = FVector(0.0f, 0.0f, -700.0f * DeltaTime);

			// swinging forces
			FVector Velocity = GetVelocity();

			//gives velocity in a direction at a tangent to the swing arc
			FVector TangentVelocity = Velocity - (FVector::DotProduct(Velocity, Direction) * Direction);

			// makes the player swing faster the further away they are from the grapple point
			float CentripedalInfluence = FMath::Clamp(Distance / GrappleRopeLength, 0.1f, 1.0f);
			FVector CentripedalForce = -Direction * FVector::DotProduct(Velocity, Direction) * CentripedalInfluence;

			// Adding player facing direction to influence the swing
			float LookInfluence = 1000.0f;
			FVector HorizontalViewDirection = FVector(ViewDirection.X, ViewDirection.Y, 0.0f).GetSafeNormal();
			float ViewDirectionDot = FVector::DotProduct(Direction, HorizontalViewDirection);

			float ClampedLookInfluence = FMath::Clamp(LookInfluence * ViewDirectionDot, -2.0f, 2.0f);
			FVector AdjustedDirection = FVector(Direction.X, Direction.Y, FMath::Max(Direction.Z, 0.3f)).GetSafeNormal();

			// force that pulls player to the target
			float PullStrength = 1 - FMath::Clamp((Distance - MinGrappleRange) / GrappleRopeLength, 0.2f, 0.6f);
			FVector PullForce = AdjustedDirection * PullSpeed * PullStrength;

			// adding player movement to influence swing 
			FVector PlayerInputInfluence = GetActorRightVector() * InputSwingStrength * MoveInput.X;

			FVector TotalForce = Gravity + TangentVelocity + CentripedalForce + PullForce + PlayerInputInfluence * DeltaTime;
			FVector ClampedForce = TotalForce.GetClampedToMaxSize(MaxSwingSpeed);

			LaunchCharacter(ClampedForce, true, true);
			//UE_LOG(LogTemp, Warning, TEXT("Speed: %f"), ClampedForce.Size());
		}
		else 
		{
			// just pulls the player like normal grapple 
			float SpeedMultiplier = FMath::Clamp(Distance / 0.01f, 1.0, 10.0f);
			FVector PullVelocity = Direction * PullSpeed * SpeedMultiplier * DeltaTime;

			LaunchCharacter(PullVelocity * 10, true, true);

		}
	}
		//FVector PullVelocity = Direction * PullSpeed * DeltaTime * 5.0f;
		//LaunchCharacter(PullVelocity, true, true);
}

// Not used, just part of the 1st person template
void AGrappleProjectCharacter::SetHasRifle(bool bNewHasRifle)
{
	bHasRifle = bNewHasRifle;
}

// Not used, just part of the 1st person template
bool AGrappleProjectCharacter::GetHasRifle()
{
	return bHasRifle;
}

void AGrappleProjectCharacter::ResetPosition()
{
	SetActorLocation(FVector(900, 900, 100));
	GetCharacterMovement()->StopMovementImmediately();
}

void AGrappleProjectCharacter::GrapplePressed()
{
	if (!IsGrappling && CanGrapple)
	{
		StartGrapple();
	}
	IsGrapplePressed = true;
}

void AGrappleProjectCharacter::ResetCooldown()
{
	CanGrapple = true;
	UE_LOG(LogTemp, Warning, TEXT("Grapple Ready"));
}

void AGrappleProjectCharacter::GrappleReleased()
{
	IsGrappling = false;
	IsGrapplePressed = false;
	CanGrapple = false;
	shouldSwing = false;
	GrappleCable->SetVisibility(false);
	GrappleCooldown = 0.5f;
}

void AGrappleProjectCharacter::StartGrapple()
{
	// If already grappling or grapple is on cooldown, do nothing
	if (!CanGrapple || IsGrappling)
	{
		return;
	}

	// Starts grappling

	//FMinimalViewInfo CameraViewInfo;
	//FirstPersonCameraComponent->GetCameraView(1.0f, CameraViewInfo);

	FVector StartLocation = GetActorLocation();
	FVector Direction = GetControlRotation().Vector();
	float PlayerPitch = GetControlRotation().Pitch;
	FVector EndLocation = StartLocation + (Direction * GrappleRange);

	FHitResult HitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this); //ensures the grapple doesn't hit the player

	GrappleCable->SetVisibility(true);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams))
	{
		if (HitResult.bBlockingHit)
		{
			if (PlayerPitch < 270.0f && PlayerPitch > 14) 
			{
				shouldSwing = true;
			}
			GrappleTarget = HitResult.Location;
			IsGrappling = true;
			//UE_LOG(LogTemp, Warning, TEXT("PlayerPitch SUCCESS: %f"), PlayerPitch);
			GrappleRopeLength = FVector::Dist(GetActorLocation(), GrappleTarget);
			LaunchCharacter(Direction, true, true);
		}
	}
	else
	{
		GrappleCable->SetMaterial(0, CableMaterialOOR);
		GrappleTarget = EndLocation;
		GrappleCable->EndLocation = GetActorTransform().InverseTransformPosition(GrappleTarget);
		//UE_LOG(LogTemp, Warning, TEXT("PlayerPitch: %f"), PlayerPitch);
		//DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.0f, 0, 2.0f);
	}
}
