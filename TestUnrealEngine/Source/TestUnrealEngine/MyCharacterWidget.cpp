// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"


void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp; // 실제 게임이 실행됐을 때 실행되는 코드
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp); // 델레게이트 연결
}

void UMyCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		BP_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
// 이렇게 하면 틱마다 데미지를 입는 경우에도 계속 실행되는데, 클라측에서 실행되기 떄문에 조금 무식하게 구현해도 됨
