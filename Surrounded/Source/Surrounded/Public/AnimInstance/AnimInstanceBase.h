// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceBase.generated.h"

class UCharacterMovementComponent;

UCLASS()
class SURROUNDED_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(BlueprintReadOnly, Category = "Surrounded Character Anim")
	float MovementSpeed = 0.0f;
	UPROPERTY(BlueprintReadOnly, Category = "Surrounded Character Anim")
	bool bShouldMove = false;
	
private:
	UPROPERTY()
	UCharacterMovementComponent* MovementComponent;


};
