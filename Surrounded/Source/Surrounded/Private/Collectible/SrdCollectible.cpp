// Copyright Lu


#include "Collectible/SrdCollectible.h"
#include "Components/SphereComponent.h"

// Temporary headers
#include "Kismet/KismetSystemLibrary.h"
#include "Character/SrdCharacter.h"
#include "Gameplay/AbilitySystem/SrdAttributeSet.h"

ASrdCollectible::ASrdCollectible()
{
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(MeshComp);
	
	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereCollider->SetupAttachment(GetRootComponent());
}

void ASrdCollectible::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (SphereCollider ==  nullptr) return;
	// bind events
	SphereCollider->OnComponentBeginOverlap.AddUniqueDynamic(this, &ASrdCollectible::OnOverlap);
	SphereCollider->OnComponentEndOverlap.AddUniqueDynamic(this, &ASrdCollectible::OnEndOverlap);
}

void ASrdCollectible::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// TEST only	
	TScriptInterface<IAbilitySystemInterface> OverlappedActor = TScriptInterface<IAbilitySystemInterface>(OtherActor);
	if (OverlappedActor == nullptr) return;

	const USrdAttributeSet* SrdAttributeSet = Cast<USrdAttributeSet>(OverlappedActor->GetAbilitySystemComponent()->GetAttributeSet(USrdAttributeSet::StaticClass()));
	USrdAttributeSet* MutableSrdAttributeSet = const_cast<USrdAttributeSet*>(SrdAttributeSet);
	float HealthRestore = 30.0f;
	MutableSrdAttributeSet->SetHealth(SrdAttributeSet->GetHealth() + HealthRestore);
	
	// Show debug text at location
	FVector TextLocation = GetActorLocation() + FVector(0.0, 0.0, 150.0);
	UKismetSystemLibrary::DrawDebugString(this, TextLocation,
	                                      FString::Printf(TEXT("Restored %f health!"), HealthRestore), nullptr,
	                                      FColor::Green, 5.0f);
	Destroy();
}

void ASrdCollectible::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}



void ASrdCollectible::BeginPlay()
{
	Super::BeginPlay();
	
}




