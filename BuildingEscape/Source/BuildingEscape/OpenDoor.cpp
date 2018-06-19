// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	Owner = GetOwner();
	/*ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();*/

}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float CurrentTime = GetWorld()->GetTimeSeconds();

	/*if (PressurePlate->IsOverlappingActor(ActorThatOpens))*/
	if (GetTotalMassOfActorsOnPlate() > 30.f)
	{
		OpenDoor();
		LastDoorOpenTime = CurrentTime;
	}
	if (LastDoorOpenTime != -1.f 
		&& CurrentTime-LastDoorOpenTime >= DoorCloseDelay)
	{
		CloseDoor();
		LastDoorOpenTime = -1.f;
	}
	
}

float UOpenDoor::GetTotalMassOfActorsOnPlate() {

	float TotalMass = 0.f;

	// Find all the overlapping actors
	TArray<AActor*> OverLappingActors;
	PressurePlate->GetOverlappingActors(OUT OverLappingActors);

	for (const auto* Actor : OverLappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName())
	}
	UE_LOG(LogTemp, Warning, TEXT("Total Mass : %f "), TotalMass)
	return TotalMass;
}
