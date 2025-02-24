// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SrdController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class IInteractInterface;

UCLASS()
class SURROUNDED_API ASrdController : public APlayerController
{
	GENERATED_BODY()

public:
	ASrdController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void Tick(float DeltaTime) override;

private:
	// ~ Enhanced input
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", meta=(DisplayName="Input Action Move"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", meta=(DisplayName="Input Action Look"))
	TObjectPtr<UInputAction> LookAction;
	// ~ End Enhanced input

	UPROPERTY(EditAnywhere, Category = "Trace Hit")
	TArray<TEnumAsByte<EObjectTypeQuery>> TraceObjectTypes;

#pragma region Interfaces
	
	UPROPERTY()
	TScriptInterface<IInteractInterface> PreviousHitActor;
	
	UPROPERTY()
	TScriptInterface<IInteractInterface> CurrentHitActor;
	
#pragma endregion

private:
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	UFUNCTION()
	void Look(const FInputActionValue& Value);

	UFUNCTION()
	void CursorTrace();


	
};




