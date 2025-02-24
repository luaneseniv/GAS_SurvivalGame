// Copyright Lu


#include "Gameplay/SrdController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Gameplay/Interface/InteractInterface.h"



ASrdController::ASrdController()
{
	bReplicates = true;
	
}

void ASrdController::BeginPlay()
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

void ASrdController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Crash if cast from InputComponent is FAILED
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this,&ASrdController::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered, this,&ASrdController::Look);
}

void ASrdController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CursorTrace();
	
}


void ASrdController::Move(const FInputActionValue& Value)
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

void ASrdController::Look(const FInputActionValue& Value)
{
	
}

void ASrdController::CursorTrace()
{
	FHitResult HitResult;

	GetHitResultUnderCursor(ECC_Visibility, false,HitResult);
	if(!HitResult.bBlockingHit) return;

	PreviousHitActor = CurrentHitActor;
	CurrentHitActor = HitResult.GetActor();
	
	/*
	 * 1. Current == previous
	 *	 1.a (Current == null) =>> Do nothing
	 *	 1.b (Current != null) =>> Do nothing
	 *		
	 * 2. Current != previous
	 *		2.a (Current != nullptr && Previous != nullptr) =>> Current->Highlight, previous->UnHighlight
	 *		2.b (Current != nullptr && Previous == nullptr) =>> Current->Highlight
	 *		2.c (Current == nullptr && Previous != nullptr) =>> previous->UnHighlight
	 *		
	 */

	if (CurrentHitActor != PreviousHitActor)
	{
		if (CurrentHitActor != nullptr && PreviousHitActor != nullptr)
		{
			CurrentHitActor->I_HighlightActor();
			PreviousHitActor->I_UnHighlightActor();
		}
		else if (CurrentHitActor != nullptr && PreviousHitActor == nullptr)
		{
			CurrentHitActor->I_HighlightActor();
		}
		else if (CurrentHitActor == nullptr && PreviousHitActor != nullptr)
		{
			PreviousHitActor->I_UnHighlightActor();
		}
	}
	
	
	
}
