// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...

	bWantsInitializeComponent = true;

	Level = 1;
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMyStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetLevel(Level);
}

void UMyStatComponent::SetLevel(int32 NewLevel)
{
	auto MyGameInstance = Cast<UMyGameInstance>(UGameplayStatics::GetGameInstance(GetWorld())); // 싱글톤처럼 언제 어디서든 긁어올 수 있는 개념?

	if (MyGameInstance)
	{
		auto StatData = MyGameInstance->GetStatData(NewLevel);
		if (StatData)
		{
			Level = StatData->Level;
			//Hp = StatData->MaxHp; // 어지간해서 UI랑 묶여있는 애들은 함수로 관리
			SetHp(StatData->MaxHp);
			MaxHp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UMyStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0)
		Hp = 0;

	OnHpChanged.Broadcast(); // 리스너(구독자) 패턴 또는 전역으로 파준 싱글톤 방식 매니저에서 가져와서 업데이트하는 스타일이 나뉨

}

void UMyStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);

	//UE_LOG(LogTemp, Warning, TEXT("OnAttacked %d"), Hp);
}

