// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MyCharacter.h"
#include "MyAIController.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true; // 설명 읽어보기
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto MyCharacter = Cast<AMyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (MyCharacter == nullptr)
		return EBTNodeResult::Failed;

	MyCharacter->Attack();
	bIsAttacking = true;

	MyCharacter->OnAttackEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});

	return Result; // 이걸 해줘도 되고 success 표시를 해주면 된다?
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (bIsAttacking == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
