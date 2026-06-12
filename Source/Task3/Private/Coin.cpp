#include "Coin.h"
#include "TimerManager.h"

ACoin::ACoin()
{
	//루트 설정
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);

	//스태틱 메시
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComponent->SetupAttachment(SceneComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMesh(TEXT("/Game/Map/_GENERATED/ay318/cube_world_powerup_coin_proto_series_24_68EB7FE5.cube_world_powerup_coin_proto_series_24_68EB7FE5"));
	if (StaticMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(StaticMesh.Object);
		SetActorScale3D(FVector(0.01f, 0.01f, 0.01f));
		StaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 6000.0f));
	}

	PrimaryActorTick.bCanEverTick = true;
	RotateSpeed = 120.0f;
}

void ACoin::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(
		Timer,
		this,
		&ACoin::RandomLocation,
		6.0f,
		true
	);
}

void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
	}
}

void ACoin::RandomLocation()
{
	float XRange = FMath::FRandRange(-3950.0f, 3950.0f);
	float YRange = FMath::FRandRange(-1200.0f, 3950.0f);
	
	SetActorLocation(FVector(XRange,YRange,900.0f));
}