#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pig.generated.h"

UCLASS()
class TASK3_API APig : public AActor
{
	GENERATED_BODY()
	
public:	
	APig();
	USceneComponent* SceneRoot;

	USkeletalMeshComponent* BodySkeletalMeshComp;
	USkeletalMeshComponent* TailSkeletalMeshComp;

	UMaterial* PigColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Number|Speed")
	float RotateSpeed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
