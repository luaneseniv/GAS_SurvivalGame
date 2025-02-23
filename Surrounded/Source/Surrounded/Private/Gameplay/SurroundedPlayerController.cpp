// Copyright Lu


#include "Gameplay/SurroundedPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"



ASurroundedPlayerController::ASurroundedPlayerController()
{
	bReplicates = true;
}

void ASurroundedPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(InputMappingContext);

	// Add input mapping context
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(InputMappingContext, 0);
	
	// Always show mouse cursor
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	// Show mouse cursor during capture
	// And not to lock the mouse to the viewport
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void ASurroundedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Crash if cast from InputComponent is FAILED
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this,&ASurroundedPlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered, this,&ASurroundedPlayerController::Look);
}


void ASurroundedPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();

	const FRotator VectorRotation = FRotator(0.0, GetControlRotation().Yaw, 0.0);
	//const FVector ForwardDirection =  RotationVector.RotateVector(FVector::ForwardVector);
	//const FVector RightDirection =  RotationVector.RotateVector(FVector::RightVector);
	const FVector ForwardDirection = FRotationMatrix(VectorRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(VectorRotation).GetUnitAxis(EAxis::Y);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void ASurroundedPlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(InputAxisVector.X);
		ControlledPawn->AddControllerPitchInput(InputAxisVector.Y);
	}
}
