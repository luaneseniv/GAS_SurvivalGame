// Copyright Lu


#include "AnimInstance/AnimInstanceBase.h"
#include "Character/SrdCharacterBase.h"
#include "GameFramework/CharacterMovementComponent.h"


void UAnimInstanceBase::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	
	if (ASrdCharacterBase* Character = Cast<ASrdCharacterBase>(TryGetPawnOwner()))
		MovementComponent = Character->GetCharacterMovement();
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (MovementComponent == nullptr) return;
	MovementSpeed = MovementComponent->Velocity.Size2D();
	bShouldMove = MovementSpeed > 0.0f;
	
}
