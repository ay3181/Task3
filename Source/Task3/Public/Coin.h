#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Coin.generated.h"

struct FTimerHandle;

UCLASS()
class TASK3_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoin();

	USceneComponent* SceneComponent;
	UStaticMeshComponent* StaticMeshComponent;
	UMaterial* Material;

	FTimerHandle Timer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Speed");
	float RotateSpeed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	void RandomLocation();

};
