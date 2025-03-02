// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorEffect.generated.h"


class UGameplayEffect;

UCLASS()
class SURROUNDED_API AActorEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	AActorEffect();

	UFUNCTION(BlueprintCallable, Category = "Gameplay Effect")
	virtual void ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GEClass);


public:
	/* Required. Set which GameplayAbility class that takes effect for this actor*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay Effect")
	TSubclassOf<UGameplayEffect> GameplayEffectClass;

};
