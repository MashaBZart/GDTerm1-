// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	
	PrimaryActorTick.bCanEverTick = true;
	//Create Static Mesh Component and Attach to Root
	FloatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	FloatMesh ->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
//if MeshAsset is found, attach to Root and set loc to 0 in xyz
	if(MeshAsset.Succeeded())
		FloatMesh-> SetStaticMesh(MeshAsset.Object);
		FloatMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	
	

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Define Actor Location and Rotation Vars
	FVector newLocation = GetActorLocation();
	FRotator newRoation = GetActorRotation();
	//Define Running time 
	float runningTime = GetGameTimeSinceCreation();
	//Add sin Math to delta height 
	float deltaHight = (FMath:: Sin(runningTime + DeltaTime)) - FMath:: Sin(runningTime);
	//Add Delta Height to Z direction *float speed 
	newLocation.Z += deltaHight * FloatSpeed;
	//Add rotation to YAW times rotation speed 
	float DeltaRotaion = DeltaTime * RotationSpeed;
	//Set Actor Location and Roation
	newRoation.Yaw += DeltaRotaion;
	SetActorLocationAndRotation(newLocation, newRoation);
	

}

