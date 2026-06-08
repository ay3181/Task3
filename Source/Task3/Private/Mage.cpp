#include "Mage.h"

// Sets default values
AMage::AMage()
{
	//루트 생성, 루트 지정
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	//몸통 컴포넌트 생성, 루트에 붙이기
	MageSkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	MageSkeletalMeshComp->SetupAttachment(SceneRoot);

	//몸통 매시 불러오기
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MageSkeletalMesh(TEXT("/Game/Fab/Stylized_Simple_Mage/stylized_simple_mage.stylized_simple_mage"));
	if (MageSkeletalMesh.Succeeded())
	{
		MageSkeletalMeshComp->SetSkeletalMesh(MageSkeletalMesh.Object);
		MageSkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.0f, 90.0f));
	}
	
	//몸통에 색 입히기
	static ConstructorHelpers::FObjectFinder<UMaterial> MageMaterial(TEXT("/Game/Feb/Object/MageBody.MageBody"));
	if (MageMaterial.Succeeded())
	{
		MageSkeletalMeshComp->SetMaterial(0, MageMaterial.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 200;
	MaxRange = 1000;

}

void AMage::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	CurrentLocation = StartLocation;
	ForwardVector = GetActorForwardVector();
}

void AMage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (FVector::Distance(StartLocation, CurrentLocation)>MaxRange)
	{
		MoveSpeed *= -1;
		SetActorRotation(FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw + 180, GetActorRotation().Roll));
	}
	CurrentLocation += ForwardVector * MoveSpeed * DeltaTime;
	SetActorLocation(FVector(CurrentLocation));
}

