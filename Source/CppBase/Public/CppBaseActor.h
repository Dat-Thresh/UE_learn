// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum EMovementState :uint8 {
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct {
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppBaseActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

protected:
    UPROPERTY(EditInstanceOnly)
	float Frequency;
    UPROPERTY(EditInstanceOnly)
	float Amplitude;
    
    FVector InitialLocation;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditInstanceOnly)
	int EnemyNum;

	UPROPERTY(EditInstanceOnly)
	bool isAlive;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();
	
	UFUNCTION(BlueprintCallable)
    void SinMovement();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;






};
