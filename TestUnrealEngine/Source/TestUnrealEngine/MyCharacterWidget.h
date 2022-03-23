// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyCharacterWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTUNREALENGINE_API UMyCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindHp(class UMyStatComponent* StatComp);

	void UpdateHp();

private:
	TWeakObjectPtr<class UMyStatComponent> CurrentStatComp;
	// ����Ʈ������

	UPROPERTY(meta=(BindWidget))
	// �������Ʈ���� �������� �������� �ֶ� �� ������ �ٷ� ������ �ǵ��� �������ش�
	class UProgressBar* BP_HpBar;
	// meta=(BindWidget)�� �������Ʈ���� ���� �� progress bar�� �˾Ƽ� ã���� ����
	// ���� �� ã���ָ� cpp�ʿ��� Cast�� ã���ָ� �ȴ�

};
