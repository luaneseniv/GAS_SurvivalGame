// Copyright Lu


#include "Character/SrdEnemy.h"
#include "Surrounded/Surrounded.h"

ASrdEnemy::ASrdEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASrdEnemy::BeginPlay()
{
	Super::BeginPlay();

	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void ASrdEnemy::I_HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	Weapon->SetRenderCustomDepth(true);
}

void ASrdEnemy::I_UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

