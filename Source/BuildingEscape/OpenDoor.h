// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UOpenDoor();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

	void OpenDoor();

	void CloseDoor();

public:
    // Called every frame
    virtual void
    TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
    UPROPERTY(EditAnywhere)    // Macro To be visible(read-only) inside editor (Details Tab)
    float OpenAngle = 90.0f;

    UPROPERTY(EditAnywhere)      // Macro to be editable inside editor (Details Tab)
    ATriggerVolume* PressurePlate;

    AActor* ActorThatOpensDoor;  // Remember pawn(current ActorThatOpensDoor) inherits from Actor
	AActor* Owner;				 // The owning door

	UPROPERTY(EditAnywhere)      // Macro to be editable inside editor (Details Tab)
	float DoorCloseDelay = 1.0f;

	float LastDoorOpenTime = 100.0f; // TODO Need some attention. Using random value !!!
};
