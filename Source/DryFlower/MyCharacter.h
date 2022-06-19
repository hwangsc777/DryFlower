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

	// Collision function for searching
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;
	bool NowCanSearch = false;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveRight(float value);
	void MoveForward(float value);

	UFUNCTION(Reliable, Server, WithValidation, BlueprintCallable, Category = MakeServer)
	void MakeServer(); 
	void MakeServer_Implementation();
	bool MakeServer_Validate();

	UFUNCTION(Reliable, Server, WithValidation, BlueprintCallable, Category = DieServer)
	void DieServer();
	void DieServer_Implementation();
	bool DieServer_Validate();
	
	UFUNCTION(Reliable, NetMulticast)
	void Make(); // F ������ �� ����
	void Make_Implementation();

	UFUNCTION(Reliable, NetMulticast)
	void Die(); // ������ �ӽ÷� G ������ �� ����			
	void Die_Implementation();		
			

    /*
	FTimerHandle WaitHandle; // ������ �ִ� �ð�
	float MakeTime = 2.0f; // 2��
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = MakeSomething, meta = (AllowPrivateAccess = "true"))
		bool MakeCheck = false; // ĳ���Ͱ� F ���� ������ ���� bool
	*/

	//void Attack();
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Attack, meta = (AllowPrivateAccess = "true"))
	//	bool IsAttacking = false;



	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Die, meta = (AllowPrivateAccess = "true"))
	bool DieCheck = false;

};
