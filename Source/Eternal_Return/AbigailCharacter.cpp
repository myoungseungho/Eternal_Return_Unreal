#include "AbigailCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"

// »ý¼ºÀÚ
AAbigailCharacter::AAbigailCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAbigailCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AAbigailCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbigailCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
