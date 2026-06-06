// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mage.generated.h"

UCLASS()
class TASK3_API AMage : public AActor
{
	GENERATED_BODY()
	
public:	
	AMage();

	USceneComponent* SceneRoot;
	USkeletalMeshComponent* MageSkeletalMeshComp;
	UMaterial* MageMaterial;

protected:
	virtual void BeginPlay() override;

public:	
		virtual void Tick(float DeltaTime) override;

};
