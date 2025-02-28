// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();

}

void AShooterAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if (LineOfSightTo(PlayerPawn)) // 시야에 들어왔을 경우
	{
		SetFocus(PlayerPawn);
		MoveToActor(PlayerPawn, AcceptanceRadius = 200);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay); // 게임플레이 우선권 해제
		StopMovement();
	}
}