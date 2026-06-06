#include "Pig.h"

APig::APig()
{
	//风飘 积己 棺 风飘 瘤沥
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	//个 积己 饶 风飘 关俊 持澜
	BodySkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BodySkeletalMesh"));
	BodySkeletalMeshComp->SetupAttachment(SceneRoot);

	//部府 积己 饶 个 关俊 持澜
	TailSkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TailSkeletalMesh"));
	TailSkeletalMeshComp->SetupAttachment(BodySkeletalMeshComp);

	//个, 部府 葛胆傅, 蹬瘤 祸 阂矾咳
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> BodySkeletalMesh(TEXT("/Game/Fab/Free_Cube_Pig_Cute_Pro_Series_00/Pig.Pig"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> TailSkeletalMesh(TEXT("/Game/Fab/Free_Cube_Pig_Cute_Pro_Series_00/Pig_Tail.Pig_Tail"));
	static ConstructorHelpers::FObjectFinder<UMaterial> PigColorMaterial(TEXT("/Game/Feb/Object/FigBody.FigBody"));

	//葛胆傅阑 哪器惩飘俊 持澜
	if (BodySkeletalMesh.Succeeded())
	{
		BodySkeletalMeshComp->SetSkeletalMesh(BodySkeletalMesh.Object);
	}
	if (TailSkeletalMesh.Succeeded())
	{
		TailSkeletalMeshComp->SetSkeletalMesh(TailSkeletalMesh.Object);
	}

	//祸 何咯
	if (PigColorMaterial.Succeeded())
	{
		BodySkeletalMeshComp->SetMaterial(0, PigColorMaterial.Object);
		TailSkeletalMeshComp->SetMaterial(0, PigColorMaterial.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotateSpeed = 120.0f;
}

void APig::BeginPlay()
{
	Super::BeginPlay();
	
}

void APig::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!FMath::IsNearlyZero(RotateSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotateSpeed * DeltaTime, 0.0f));
	}
}

