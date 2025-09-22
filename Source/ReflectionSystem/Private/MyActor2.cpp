// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor2.h"

// Sets default values
AMyActor2::AMyActor2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Scene);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SMAsset(TEXT("/Game/Resources/Props/SM_Star_B.SM_Star_B"));
	if (SMAsset.Succeeded()) {
		StaticMesh->SetStaticMesh(SMAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MAssest(TEXT("/Game/Resources/Props/Materials/M_Chair.M_Chair"));
	if (MAssest.Succeeded()) {
		StaticMesh->SetMaterial(0, MAssest.Object);
	}

	MoveSpeed = 100.0f;
	MaxRange = 100.0f;
}

// Called when the game starts or when spawned
void AMyActor2::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMyActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if ((GetActorLocation().Z - StartLocation.Z > MaxRange) || (StartLocation.Z - GetActorLocation().Z > MaxRange))
	{
		MoveSpeed = -MoveSpeed;
	}
	AddActorLocalOffset(FVector(0.0f, 0.0f, MoveSpeed * DeltaTime));
}

