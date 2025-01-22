// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class HELLOUNREAL_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
// ; 아니고 :
public:
	const FString Win = TEXT("승리");
	const FString Loss = TEXT("패배");
	const FString Draw = TEXT("비겼다");
	const FString Scissors = TEXT("가위");
	const FString Rock = TEXT("바위");
	const FString Paper = TEXT("보");

	void Init() override;

	int32 Damage(int32 MyDamage, int32 EnemyHP);

	int32 UseSkill(int32 Mana);

	//반환하는타입 함수명(필요로하는 인자, 인자, 인자, 인자);
	FString SetAttack(int32 Attack);

	FString Judge(int32 MyValue, int32 Enemy);
};
