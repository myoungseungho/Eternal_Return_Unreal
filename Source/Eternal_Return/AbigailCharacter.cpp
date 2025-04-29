// Fill out your copyright notice in the Description page of Project Settings.


#include "AbigailCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAbigailCharacter::AAbigailCharacter()
{
    // Tick 활성화
    PrimaryActorTick.bCanEverTick = true;

    // SpringArm 생성
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->TargetArmLength = 300.0f; // 카메라 거리
    SpringArm->bUsePawnControlRotation = true; // 마우스 방향에 따라 회전

    // Camera 생성
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = false; // Camera 자체는 회전하지 않음

    // 이동 세팅 (선택사항)
    GetCharacterMovement()->bOrientRotationToMovement = true; // 이동 방향을 따라 몸이 회전
    bUseControllerRotationYaw = false; // 직접적인 캐릭터 회전은 끄기

}

// Called when the game starts or when spawned
void AAbigailCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAbigailCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAbigailCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // 입력 바인딩
    PlayerInputComponent->BindAxis("MoveForward", this, &AAbigailCharacter::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AAbigailCharacter::MoveRight);
    PlayerInputComponent->BindAxis("Turn", this, &AAbigailCharacter::Turn);
    PlayerInputComponent->BindAxis("LookUp", this, &AAbigailCharacter::LookUp);

}

void AAbigailCharacter::MoveForward(float Value)
{
    if (Controller && Value != 0.0f)
    {
        // 캐릭터가 바라보는 방향을 기준으로 전/후 이동
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
        AddMovementInput(Direction, Value);
    }
}

void AAbigailCharacter::MoveRight(float Value)
{
    if (Controller && Value != 0.0f)
    {
        // 캐릭터가 바라보는 방향을 기준으로 좌/우 이동
        const FRotator Rotation = Controller->GetControlRotation();
        const FRotator YawRotation(0, Rotation.Yaw, 0);

        const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
        AddMovementInput(Direction, Value);
    }
}

void AAbigailCharacter::Turn(float Value)
{
    AddControllerYawInput(Value);
}

void AAbigailCharacter::LookUp(float Value)
{
    AddControllerPitchInput(Value);
}
