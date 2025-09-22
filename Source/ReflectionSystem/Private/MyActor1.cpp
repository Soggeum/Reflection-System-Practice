// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor1.h"

// Sets default values
AMyActor1::AMyActor1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SMAsset(TEXT("/Game/Resources/Props/SM_Coin_A.SM_Coin_A"));
	if (SMAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(SMAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MAssest(TEXT("/Game/Resources/Props/Materials/M_TableRound.M_TableRound"));
	if (MAssest.Succeeded()) {
		StaticMesh->SetMaterial(0, MAssest.Object);
	}

	RotationSpeed = 90.0f;
}

// Called when the game starts or when spawned
void AMyActor1::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
}

