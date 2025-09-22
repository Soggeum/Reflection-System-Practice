// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor1.generated.h"

UCLASS()
class REFLECTIONSYSTEM_API AMyActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor1();

protected:
	USceneComponent* Scene;
	UStaticMeshComponent* StaticMesh;
	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "Platform Settings")
	float RotationSpeed;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
