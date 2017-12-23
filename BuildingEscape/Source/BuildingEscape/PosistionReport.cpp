// Fill out your copyright notice in the Description page of Project Settings.

#include "PosistionReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPosistionReport::UPosistionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPosistionReport::BeginPlay()
{
	Super::BeginPlay();

	FString objectName = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("PositionReporting for %s"), *objectName);
}


// Called every frame
void UPosistionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

