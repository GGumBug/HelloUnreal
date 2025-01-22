// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	// 코드에서 \ 하나 출력하려면 \\

	/*UE_LOG(LogTemp, Warning, TEXT("\\    /\\"));
	UE_LOG(LogTemp, Warning, TEXT(" )  ( ')"));
	UE_LOG(LogTemp, Warning, TEXT("(  /  )"));
	UE_LOG(LogTemp, Warning, TEXT(" \\(__)|"));

	UE_LOG(LogTemp, Warning, TEXT("|\\_/|"));
	UE_LOG(LogTemp, Warning, TEXT("|q p|   /}"));
	UE_LOG(LogTemp, Warning, TEXT("( 0 )\"\"\"\\"));
	UE_LOG(LogTemp, Warning, TEXT("|\"^\"'   |"));
	UE_LOG(LogTemp, Warning, TEXT("||_/=\\__|"));*/

	/*int32 a = 6;
	bool bDeath = true;
	char b = 'A';
	int32 e = 32767;
	float f = 3.14;
	double g  = 3.141592;
	char hello[] = "Hello";*/

	/*int32 result = 0;*/

	/*result = a + b;
	result = a - b;
	result = a * b;
	result = a / b;
	result = a % b;*/

	//result += a; //result = result + a;
	//result -= a; //result = result - a;
	//result *= a; //result = result * a;
	//result /= a; //result = result / a;
	//result %= a; //result = result % a;

	//result++; //result + 1; 반환하고 +1을 해준다.
	//++result; //+1을 해주고 반환을 해준다.
	//result--; //반환하고 -1을 해준다.
	//result--; //-1을 해주고 반환을 해준다.

	//비교연산
	/*a == b
	a != b
	a > b
	a >= b
	a < b
	a <= b*/

	int32 b = 7;

	//논리 연산
	/*! true면 false 반환, false면 true 반환
	&& AND
	|| OR*/

	bool bA = true;
	bool bB = false;
	bool bC = true;

	//분기문
	//if
	//else if
	//else
	//swich

	/*if (ValueA > 100)
	{
		UE_LOG(LogTemp, Warning, TEXT("error"));
	}
	else if (90 <= ValueA && ValueA <= 100)
	{
		UE_LOG(LogTemp, Warning, TEXT("A"));
	}
	else if (90 <= ValueA && ValueA <= 89)
	{
		UE_LOG(LogTemp, Warning, TEXT("B"));
	}
	else if (90 <= ValueA && ValueA <= 79)
	{
		UE_LOG(LogTemp, Warning, TEXT("C"));
	}
	else if (60 <= ValueA && ValueA <= 69)
	{
		UE_LOG(LogTemp, Warning, TEXT("D"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("F"));
	}*/



	//반복문
	// ~뭐 하는 동안
	/*while (ValueA <= 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("%d"), ValueA);
		ValueA++;
	}*/

	int32 ValueA = 11;

	/*do
	{

		UE_LOG(LogTemp, Warning, TEXT("%d"), ValueA);
		ValueA++;

	} while (ValueA <= 10);*/

	/*int32 TopLine = 100;

	for (int32 i = 1; i <= TopLine; i++)
	{
		FString Line = "";
		for (int32 j = 0; j < TopLine - i; j++)
		{
			Line.Append(" ");
		}

		for (int32 a = 0; a < 2 * i - 1; a++)
		{
			Line.Append("*");
		}

		UE_LOG(LogTemp, Warning, TEXT("%s"), *Line);
	}*/

	//처음 넣은 값 ~ 뒤에 넣은 값까지의 정수중 랜덤으로 하나를 출력합니다.
	//언리얼 엔진에서는 UTF-16으로 문자 인코딩을 하는데 TEXT()매크로를 감싸주지 않으면
	//UTF-16 변환을 못시켜줘서 깨지게 되는 겁니다.

	int32 Enemy = FMath::RandRange(0, 2); //0~2
	int32 MyValue = FMath::RandRange(0, 2);

	FString EnemyAttack;
	FString MyAttack;

	//랜덤으로 생성 된 숫자를 문자로 변환해보자

	MyAttack = SetAttack(MyValue);
	EnemyAttack = SetAttack(Enemy);

	FString Rsult = Judge(MyValue, Enemy);

	UE_LOG(LogTemp , Warning, TEXT("내가 낸 패 : %s  적이 낸 패 : %s %s!"), *MyAttack, *EnemyAttack, *Rsult)
}

int32 UMyGameInstance::Damage(int32 MyDamage, int32 EnemyHP)
{
	return EnemyHP - MyDamage;
}

int32 UMyGameInstance::UseSkill(int32 Mana)
{
	int32 Result = Mana - 3;
	UE_LOG(LogTemp, Warning, TEXT("마나가 %d 만큼 남았습니다."), Result);
	return Result;
}

FString UMyGameInstance::SetAttack(int32 Attack)
{
	FString Result;

	switch (Attack) // 0 ~ 2
	{
	case 0:
		Result = Scissors;
		break;
	case 1:
		Result = Rock;
		break;
	case 2:
		Result = Paper;
		break;
	}

	return Result;
}

FString UMyGameInstance::Judge(int32 MyValue, int32 Enemy)
{
	if (MyValue == Enemy)
	{
		return Draw;
	}
	else if ((MyValue == 0 && Enemy == 1) || (MyValue == 1 && Enemy == 2) || (MyValue == 2 && Enemy == 0))
	{
		return Loss;
	}
	else
	{
		return Win;
	}
}
