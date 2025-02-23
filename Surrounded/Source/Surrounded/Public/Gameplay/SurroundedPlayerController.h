// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SurroundedPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class SURROUNDED_API ASurroundedPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASurroundedPlayerController();

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	// ********* Variables *********
	UPROPERTY(EditAnywhere, Category = "Enhanced Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", meta=(DisplayName="Input Action Move"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Enhanced Input", meta=(DisplayName="Input Action Look"))
	TObjectPtr<UInputAction> LookAction;

private:
	// ********* FUNCTIONS *********
	UFUNCTION()
	void Move(const FInputActionValue& Value);
	
	UFUNCTION()
	void Look(const FInputActionValue& Value);


	
};
