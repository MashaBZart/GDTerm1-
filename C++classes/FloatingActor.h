// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class T2W1_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();
	//Define static Mesh component 
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FloatMesh;

	//Define Speed of FLoat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "FloatingActor")
	float FloatSpeed =29.0f;
	//Define Rotation Speed 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FloatingActor")
	float RotationSpeed = 20.0f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
