// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class DRYFLOWER_API AMyCharacter : public ACharacter
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
	AMyCharacter();

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


	void Make(); // F ������ �� ����

	/*
	FTimerHandle WaitHandle; // ������ �ִ� �ð�
	float MakeTime = 2.0f; // 2��
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MakeSomething, meta = (AllowPrivateAccess = "true"))
		bool MakeCheck = false; // ĳ���Ͱ� F ���� ������ ���� bool
	*/

	void Attack(); // ��Ŭ�� ������ �� ����

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
		bool IsAttacking = false;

	UFUNCTION(BlueprintCallable, Category = Die)
	void Die(); // ������ �ӽ÷� G ������ �� ����
	bool DieCheck = false;

};
