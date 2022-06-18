// Fill out your copyright notice in the Description page of Project Settings.


#include "MyMurdererCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Controller.h"

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

// Sets default values
AMyMurdererCharacter::AMyMurdererCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// ĸ�� �ݸ��� ũ�� ����
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// ��Ʈ�ѷ��� ȸ���� �� ĳ���ʹ� ȸ������ �ʵ��� ����
	// ĳ���Ͱ� ī�޶� ������ �ֵ��� ���д�
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ĳ���� �����Ʈ ����
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// ī�޶� �� ���� (�浹�� �߻��� ��� �÷��̾� ������ �ٰ������� �ϴ� ��)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 900.0f;
	CameraBoom->SetRelativeRotation(FRotator(-89.f, -90.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;


	// ĳ���͸� ����ٴ� ī�޶� ����
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

}

// Called when the game starts or when spawned
void AMyMurdererCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyMurdererCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyMurdererCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyMurdererCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyMurdererCharacter::MoveForward);

	//PlayerInputComponent->BindAction("Make", IE_Pressed, this, &AMyMurdererCharacter::Make);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyMurdererCharacter::Attack);
}

void AMyMurdererCharacter::MoveRight(float Value)
{
	const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
	const FVector Direction = UKismetMathLibrary::GetRightVector(YawRotation);
	AddMovementInput(Direction, Value);
}


void AMyMurdererCharacter::MoveForward(float Value)
{
	const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
	const FVector Direction = UKismetMathLibrary::GetForwardVector(YawRotation);
	AddMovementInput(Direction, Value);
}

/*
void AMyMurdererCharacter::Make() //���߿� Search�� ����
{
	//��ϵ� ��Ÿ�� ���
	if (1)
	{
		//���Գ� Ȯ���ϴ� �α� �޽���
		//UE_LOG(LogTemp, Log, TEXT("Log Message"));
		PlayAnimMontage(MakeAnim, 1.f, FName("start_1"));

		CameraBoom->TargetArmLength = 400.0f;
		CameraBoom->SetRelativeRotation(FRotator(-60.f, -90.f, 0.f));
	}

	//����� �߿� �� �����̰� �ϱ�
	//MakeCheck = true;

	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			// MakeTime(�ð�)�� �Ʒ� �ڵ� ����

			MakeCheck = false;

		}), MakeTime, false);
}
*/

void AMyMurdererCharacter::Attack() //���θ� ���� �ִϸ��̼� ���
{
	//��ϵ� ��Ÿ�� ���
	if (IsAttacking == false)
	{
		//���Գ� Ȯ���ϴ� �α� �޽���
		//UE_LOG(LogTemp, Log, TEXT("Log Message"));
		PlayAnimMontage(MakeAnim, 1.f, FName("start_1"));
	}
}