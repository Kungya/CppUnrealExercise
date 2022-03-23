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
	// 스마트포인터

	UPROPERTY(meta=(BindWidget))
	// 블루프린트에서 툴상으로 만들어줬던 애랑 이 변수랑 바로 매핑이 되도록 유도해준다
	class UProgressBar* BP_HpBar;
	// meta=(BindWidget)이 블루프린트에서 만든 그 progress bar를 알아서 찾아줄 것임
	// 만약 못 찾아주면 cpp쪽에서 Cast로 찾아주면 된다

};
