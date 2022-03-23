// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacterWidget.h"
#include "MyStatComponent.h"
#include "Components/ProgressBar.h"


void UMyCharacterWidget::BindHp(class UMyStatComponent* StatComp)
{
	CurrentStatComp = StatComp; // ���� ������ ������� �� ����Ǵ� �ڵ�
	StatComp->OnHpChanged.AddUObject(this, &UMyCharacterWidget::UpdateHp); // ��������Ʈ ����
}

void UMyCharacterWidget::UpdateHp()
{
	if (CurrentStatComp.IsValid())
		BP_HpBar->SetPercent(CurrentStatComp->GetHpRatio());
}
// �̷��� �ϸ� ƽ���� �������� �Դ� ��쿡�� ��� ����Ǵµ�, Ŭ�������� ����Ǳ� ������ ���� �����ϰ� �����ص� ��
