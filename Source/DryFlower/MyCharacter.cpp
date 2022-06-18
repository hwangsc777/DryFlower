// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Controller.h"

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Ä¸ï¿½ï¿½ ï¿½Ý¸ï¿½ï¿½ï¿½ Å©ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// ï¿½ï¿½Æ®ï¿½Ñ·ï¿½ï¿½ï¿½ È¸ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ Ä³ï¿½ï¿½ï¿½Í´ï¿½ È¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Êµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
	// Ä³ï¿½ï¿½ï¿½Í°ï¿½ Ä«ï¿½Þ¶ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Öµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½Ð´ï¿½
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Ä³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Æ® ï¿½ï¿½ï¿½ï¿½
	GetCharacterMovement()->bOrientRotationToMovement = true;

	// Ä«ï¿½Þ¶ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ (ï¿½æµ¹ï¿½ï¿½ ï¿½ß»ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ ï¿½Ã·ï¿½ï¿½Ì¾ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ù°ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ï´ï¿½ ï¿½ï¿½)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 900.0f;
	CameraBoom->SetRelativeRotation(FRotator(-89.f, -90.f, 0.f));
	CameraBoom->bUsePawnControlRotation = false;
	CameraBoom->bInheritPitch = false;
	CameraBoom->bInheritYaw = false;
	CameraBoom->bInheritRoll = false;


	// Ä³ï¿½ï¿½ï¿½Í¸ï¿½ ï¿½ï¿½ï¿½ï¿½Ù´ï¿½ Ä«ï¿½Þ¶ï¿½ ï¿½ï¿½ï¿½ï¿½
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	/*
	static ConstructorHelpers::FObjectFinder<UAnimMontage> Cha2_MakeObject
	(TEXT("AnimMontage'/Game/Character/Animation/Mixamo_Adam/Anim2/Cha2_Make.Cha2_Make'"));
	if (Cha2_MakeObject.Succeeded())
	{
		MakeAnim = Cha2_MakeObject.Object;
	}*/
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);

	PlayerInputComponent->BindAction("Make", IE_Pressed, this, &AMyCharacter::Make);
<<<<<<< HEAD
	//PlayerInputComponent->BindAction("Die", IE_Pressed, this, &AMyCharacter::Die);
	//PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyCharacter::Attack);
=======
	PlayerInputComponent->BindAction("Die", IE_Pressed, this, &AMyCharacter::Die); //ï¿½Ó½ï¿½ï¿½ï¿½
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AMyCharacter::Attack);
>>>>>>> 5965054d6e832331ded94251a7ca92d3bd55e57f
}

void AMyCharacter::MoveRight(float Value)
{
	if (DieCheck == false)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = UKismetMathLibrary::GetRightVector(YawRotation);
		AddMovementInput(Direction, Value);
		if (Value != 0.f)
		{
			CameraBoom->TargetArmLength = 900.0f;
			CameraBoom->SetRelativeRotation(FRotator(-89.f, -90.f, 0.f));
			StopAnimMontage(MakeAnim);
		}
	}
}


void AMyCharacter::MoveForward(float Value)
{
	if (DieCheck == false)
	{
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = UKismetMathLibrary::GetForwardVector(YawRotation);
		AddMovementInput(Direction, Value);
		if (Value != 0.f)
		{
			CameraBoom->TargetArmLength = 900.0f;
			CameraBoom->SetRelativeRotation(FRotator(-89.f, -90.f, 0.f));
			StopAnimMontage(MakeAnim);
		}
	}
}

<<<<<<< HEAD
void AMyCharacter::NotifyActorBeginOverlap(AActor* OtherActor)
{
	//UE_LOG(LogTemp, Log, TEXT("can"));
	NowCanSearch = true;
}

void AMyCharacter::NotifyActorEndOverlap(AActor* OtherActor)
{
	//UE_LOG(LogTemp, Log, TEXT("cannot"));
	NowCanSearch = false;
}

void AMyCharacter::Make() //³ªÁß¿¡ Search·Î º¯°æ
{
	//µî·ÏµÈ ¸ùÅ¸ÁÖ Àç»ý
	if (NowCanSearch == true)
=======
void AMyCharacter::Make() //ï¿½ï¿½ï¿½ß¿ï¿½ Searchï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½
{
	//ï¿½ï¿½Ïµï¿½ ï¿½ï¿½Å¸ï¿½ï¿½ ï¿½ï¿½ï¿½
	if (MakeAnim)
>>>>>>> 5965054d6e832331ded94251a7ca92d3bd55e57f
	{
		//ï¿½ï¿½ï¿½Ô³ï¿½ È®ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½Î±ï¿½ ï¿½Þ½ï¿½ï¿½ï¿½
		PlayAnimMontage(MakeAnim, 1.f, FName("start_1"));

		CameraBoom->TargetArmLength = 400.0f;
		CameraBoom->SetRelativeRotation(FRotator(-60.f, -90.f, 0.f));
	}

	/*
	//ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ß¿ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ì°ï¿½ ï¿½Ï±ï¿½
	//MakeCheck = true;

	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			// MakeTime(ï¿½Ã°ï¿½)ï¿½ï¿½ ï¿½Æ·ï¿½ ï¿½Úµï¿½ ï¿½ï¿½ï¿½ï¿½

			MakeCheck = false;

		}), MakeTime, false);
	*/
}

<<<<<<< HEAD
/*
void AMyCharacter::Attack() //»ìÀÎ¸¶ °ø°Ý ¾Ö´Ï¸ÞÀÌ¼Ç Ãâ·Â, Áö±ÝÀº »ýÁ¸ÀÚµµ ÀÛµ¿ÇÔ ³ªÁß¿¡ ³ª´²¾ß µÊ
=======
void AMyCharacter::Attack() //ï¿½ï¿½ï¿½Î¸ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½Ö´Ï¸ï¿½ï¿½Ì¼ï¿½ ï¿½ï¿½ï¿½, ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Úµï¿½ ï¿½Ûµï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ß¿ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½
>>>>>>> 5965054d6e832331ded94251a7ca92d3bd55e57f
{
	//ï¿½ï¿½Ïµï¿½ ï¿½ï¿½Å¸ï¿½ï¿½ ï¿½ï¿½ï¿½
	if (IsAttacking == false)
	{
		//ï¿½ï¿½ï¿½Ô³ï¿½ È®ï¿½ï¿½ï¿½Ï´ï¿½ ï¿½Î±ï¿½ ï¿½Þ½ï¿½ï¿½ï¿½
		//UE_LOG(LogTemp, Log, TEXT("Log Message"));
		PlayAnimMontage(MakeAnim, 1.f, FName("start_1"));
	}

}
*/ // »ìÀÎ¸¶¿ë ÇÔ¼ö

void AMyCharacter::Die() //Ä³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½Ö´Ï¸ï¿½ï¿½Ì¼ï¿½
{
	//UE_LOG(LogTemp, Log, TEXT("Log Message"));
	DieCheck = true;
	//Ä³ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½Ã¹Ä·ï¿½ï¿½ï¿½Æ®
	GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	GetMesh()->SetSimulatePhysics(true);
}