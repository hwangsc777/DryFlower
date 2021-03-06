// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "EnumHeader.h"
#include "MyCharacter.h"
#include "Net/UnrealNetwork.h"
#include "MainLevelScript.generated.h"

/**
 * 
 */
UCLASS()
class DRYFLOWER_API AMainLevelScript : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> corriderRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> playerSpawnRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> enemySpawnRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom01_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom01_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom02_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom02_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom03_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom03_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom04_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom04_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom05_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> restrictedRoom05_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> escapeRoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> officeRoom_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> officeRoom_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> officeRoom_2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> labatoryRoom_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> labatoryRoom_1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> labatoryRoom_2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> labatoryRoom_3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> loungeRoom_0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TSubclassOf<AActor> loungeRoom_1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TArray<FRoomInfo> roomInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoomActorsRef, Replicated)
	TArray<AActor*> pawnList;

	UFUNCTION(BlueprintCallable)
	void InitialRoomSetup();

	//For Algorithm

	//????????? ????????? ???????????? ?????? ??? ??????
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Algorithm, Replicated)
	int maxPlayerSpawn;

	UPROPERTY(Replicated)
	int currentPlayerSpawn = 0;

	//UPROPERTY(Replicated)
	TArray<FRoomInfo*> checkedList;

	//???????????? ???????????? ?????? ????????????????????? ??? ????????? ?????? ????????????
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Algorithm, Replicated)
	int minBorder;

	//minBorder????????? ????????? ????????? ?????? ????????? ????????? ?????? ???????????? ??????
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Algorithm, Replicated)
	int maxBorder;

	void RoomCreateAlgorithm(int currentRoomNum);
	void AddAnotherPlayerRoom(int distance);
	bool CheckIsInBound(int roomIndex, Arrow arrow, int minX, int maxX, int minY, int maxY, int width);
	bool CanMakePlayerSpawnRoom(int currentRoomNum, Arrow arrow, int distance);
	int GetRoomNum(int currentRoomNum, Arrow arrow);
	RoomType GetRoomType(int currentRoomNum, Arrow arrow);
	void SetRoomType(int currentRoomNum, Arrow arrow, RoomType roomType);
	void SetRoomDoor(int currentRoomNum, Arrow arrow, bool active);
	void SetRoomWall(int currentRoomNum, Arrow arrow, bool active);
	bool CheckWallExist(int currentRoomNum, Arrow arrow);
	void ConnectingTest();
	int GetDestinationDistance(int currentRoomNum, int destinationRoomNum, int beforeRoomNum);
	void MakeRestrictedRoom();
	void SetRestrictedWallAndDoor(int currentRoomNum, int nextRoomNum, Arrow arrow);
};