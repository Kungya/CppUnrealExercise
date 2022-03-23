// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH")); // 이걸 함으로써 자동 메모리 관리가 되는 것(스마트 포인터처럼)

	RootComponent = Mesh; // 규칙?

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM(TEXT("StaticMesh'/Game/StarterContent/Props/SM_Couch.SM_Couch'"));

	if (SM.Succeeded())
	{
		Mesh->SetStaticMesh(SM.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// 카테코리, 로깅 수준, 형식, 인자
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay %d"), 3);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Error, TEXT("Tick %f"), DeltaTime);
	AddActorLocalRotation(FRotator(0.f, RotateSpeed * DeltaTime, 0.f));
}

