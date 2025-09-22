// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor2.generated.h"

UCLASS()
class REFLECTIONSYSTEM_API AMyActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor2();

protected:
	USceneComponent* Scene;
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	FVector StartLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform Settings")
	float MaxRange;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
