// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnumHeader.generated.h"

UCLASS()
class DRYFLOWER_API AEnumHeader : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnumHeader();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

UENUM(BlueprintType)
enum class RoomType : uint8
{
	None			UMETA(DispalyName = "None"),
	Corrider		UMETA(DisplayName = "Corrider"),
	PlayerSpawn		UMETA(DisplayName = "PlayerSpawn"),
	EnemySpawn		UMETA(DisplayName = "EnemySpawn"),
	Restricted01_0	UMETA(DisplayName = "Restricted01_0"),
	Restricted01_1	UMETA(DisplayName = "Restricted01_1"),
	Restricted02_0	UMETA(DisplayName = "Restricted02_0"),
	Restricted02_1	UMETA(DisplayName = "Restricted02_1"),
	Restricted03_0	UMETA(DisplayName = "Restricted03_0"),
	Restricted03_1	UMETA(DisplayName = "Restricted03_1"),
	Restricted04_0	UMETA(DisplayName = "Restricted04_0"),
	Restricted04_1	UMETA(DisplayName = "Restricted04_1"),
	Restricted05_0	UMETA(DisplayName = "Restricted05_0"),
	Restricted05_1	UMETA(DisplayName = "Restricted05_1"),
	Escape			UMETA(DisplayName = "Escape"),
	Office_0		UMETA(DisplayName = "Office_0"),
	Office_1		UMETA(DisplayName = "Office_1"),
	Office_2		UMETA(DisplayName = "Office_2"),
	Labatory_0		UMETA(DisplayName = "Labatory_0"),
	Labatory_1		UMETA(DisplayName = "Labatory_1"),
	Labatory_2		UMETA(DisplayName = "Labatory_2"),
	Labatory_3		UMETA(DisplayName = "Labatory_3"),
	Lounge_0		UMETA(DisplayName = "Lounge_0"),
	Lounge_1		UMETA(DisplayName = "Lounge_1"),
};

UENUM()
enum class Arrow : uint8
{
	None,
	Top,
	Bottom,
	Left,
	Right,
};

USTRUCT(Atomic, BlueprintType)
struct FRoomInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int roomNumber;

	int maxDoorCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	RoomType roomType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool leftWall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool rightWall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool topWall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bottomWall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool leftDoor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool rightDoor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool topDoor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bottomDoor;

	void SetWallAndDoor(bool left_wall, bool right_wall, bool top_wall, bool bottom_wall, bool left_door, bool right_door, bool top_door, bool bottom_door)
	{
		leftWall = left_wall;
		rightWall = right_wall;
		topWall = top_wall;
		bottomWall = bottom_wall;

		leftDoor = left_door;
		rightDoor = right_door;
		topDoor = top_door;
		bottomDoor = bottom_door;
	}
};