// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	// How far ahead of the player can we reach	in cm
	float Reach = 100.f;

	//
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;
	
	// Ray-Cast and grab what's in reach
	void Grab();
	// Called when grab is released
	void Released();
	//Find the Input controller
	void FindInputComponentHandle();
	//Find the PhysicsComponent  Handle
	void FindPhysicsHandleComponent();
	// Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
	
	FVector GetReachLineStart();
	// Return the end of the line trace
	FVector GetReachLineEnd();
};
 