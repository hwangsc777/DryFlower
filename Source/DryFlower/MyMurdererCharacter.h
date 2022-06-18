// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MyMurdererCharacter.generated.h"

UCLASS()
class DRYFLOWER_API AMyMurdererCharacter : public ACharacter
{
	GENERATED_BODY()
		//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	//ī�޶�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MyTPS_Cam, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation, meta = (AllowPrivateAccess = "true"))
		class UAnimMontage* MakeAnim;

public:
	// Sets default values for this character's properties
	AMyMurdererCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float value);
	void MoveForward(float value);

	//void Make(); // F ������ �� ����

	void Attack(); // ��Ŭ�� ������ �� ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
		bool IsAttacking = false;

};
