// Fill out your copyright notice in the Description page of Project Settings.


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	//Get references and game win/lose conditions.
	
	//Call HandleGamestart() to initialise  the start countdown, turret activation, pawn check etc.
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	//Check what type of actor died. if turret, tally. If Player go to lose condition.
}

void ATankGameModeBase::HandleGameStart()
{
	// Initialise the start condition , turret activation,pawncheck
	//Call Blueprint version Gamestart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
	//See if player has destroyed all turrets , show him result
	//else if turret destroyed player, show lose result.
	//Call Blueprint version GameOver(Bool)
}


