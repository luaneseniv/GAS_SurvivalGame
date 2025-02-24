// Copyright Lu


#include "AnimInstance/AnimInstanceBase.h"
#include "Character/CharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"


void UAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (ACharacterBase* Character = Cast<ACharacterBase>(TryGetPawnOwner()))
		MovementComponent = Character->GetCharacterMovement();
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//check(MovementComponent) // DEBUG
	if (MovementComponent == nullptr) return;
	MovementSpeed = MovementComponent->Velocity.Size2D();
	bShouldMove = MovementSpeed > 0.0f;
	
}
