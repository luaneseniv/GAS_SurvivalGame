// Copyright Lu

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SrdCollectible.generated.h"

class USphereComponent;

UCLASS()
class SURROUNDED_API ASrdCollectible : public AActor
{
	GENERATED_BODY()
	
public:
	//========================================================================================
	// PROPERTIES & VARIABLES
	//========================================================================================


	//========================================================================================
	// FUNCTIONS
	//========================================================================================
	ASrdCollectible();
	
	virtual void PostInitializeComponents() override;
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
protected:
	//========================================================================================
	// PROPERTIES & VARIABLES
	//========================================================================================
	
	
	//========================================================================================
	// FUNCTIONS
	//========================================================================================
	virtual void BeginPlay() override;
	

private:
	//========================================================================================
	// PROPERTIES & VARIABLES
	//========================================================================================
	UPROPERTY(VisibleDefaultsOnly)
	TObjectPtr<UStaticMeshComponent> MeshComp;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USphereComponent> SphereCollider;
	
	
	//========================================================================================
	// FUNCTIONS
	//========================================================================================


};
