// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "TimerManager.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation = FVector(FMath::FRandRange(10.0f, 1000.0f),
                            FMath::FRandRange(10.0f, 1000.0f), 
							0.0f);

		
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation() {

	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), this->GetActorNameOrLabel().GetCharArray().GetData());
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("IsAlive; %i"), isAlive);
}

void ACppBaseActor::SinMovement() {
  float result;
  result = FMath::Sin(Frequency * GetWorld()->GetTimeSeconds()) * Amplitude;
  this->SetActorLocation(FVector(this->GetActorLocation().X,
                                 this->GetActorLocation().Y,
                                 this->GetActorLocation().Z + result));
}

