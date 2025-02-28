// Copyright Lu


#include "Character/SrdCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Gameplay/SrdController.h"
#include "Gameplay/SrdPlayerState.h"
#include "Gameplay/AbilitySystem/SrdAbilitySystemComponent.h"
#include "UI/HUD/SrdHUD.h"

ASrdCharacter::ASrdCharacter()
{
	// Setup Spring Arm and Camera for Top-Down
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-55.0, 0.0, 0.0)); // Now in UE5, FRotator used Double instead of Float
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	

	/*
	 *Configurations for Top-Down behaviors:
	 * Spring Arm
	 * Pawn
	 * Movement Component
	 */
	Camera->bUsePawnControlRotation = false;
	
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bEnableCameraLag = true;
	SpringArm->TargetArmLength = 1200.0f;
	SpringArm->bUsePawnControlRotation = false;
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationPitch = false;
	
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0, 450.0, 0.0);
	
}

void ASrdCharacter::InitAbilityActorInfo()
{
	ASrdPlayerState* SrdPlayerState = GetPlayerState<ASrdPlayerState>();
	if (SrdPlayerState)
	{
		//SrdPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(SrdPlayerState, this);
		AbilitySystemComponent = SrdPlayerState->GetAbilitySystemComponent();
		AttributeSet = SrdPlayerState->GetAttributeSet();

		// for player character. Owner will be PlayerState, Avatar will be PlayerCharacter
		AbilitySystemComponent->InitAbilityActorInfo(SrdPlayerState, this);

		// Create new OverlayWidget and add to viewport
		// Also construct necessary params for OverlayWidgetController
		if (ASrdController* SrdController = Cast<ASrdController>(GetController()))
			if (ASrdHUD* SrdHUD = SrdController->GetHUD<ASrdHUD>())
				SrdHUD->InitOverlayWidget(SrdController, SrdPlayerState, AbilitySystemComponent, AttributeSet);
		
	}
}

// Setup ASC on the server
void ASrdCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();
}

// Setup ASC on client
void ASrdCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();
}


void ASrdCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}
