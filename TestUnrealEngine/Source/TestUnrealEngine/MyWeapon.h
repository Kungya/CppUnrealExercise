// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyWeapon.generated.h"

UCLASS()
class TESTUNREALENGINE_API AMyWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override; // 델레게이트처럼 콜백방식?

private:
	UFUNCTION() // 언리얼에서 관리하는 함수라는 힌트를 줘야 맵핑이 됨
	void OnCharacterOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	// Called every frame
	/*virtual void Tick(float DeltaTime) override;*/

public:

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Weapon;

	UPROPERTY(VisibleAnywhere)
	class  UBoxComponent* Trigger;

};
