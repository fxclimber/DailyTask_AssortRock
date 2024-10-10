#include "TextRPGCore.h"
#include "Player.h"
#include "World.h"
#include <iostream>

//플레이어 1명, 다른 사람이 만들수도 있으나, 만들기 금지!
APlayer MainPlayer;
UWorld World;

APlayer& TextRPGCore::GetPlayer()
{
	return MainPlayer;
}



TextRPGCore::TextRPGCore()
{

}

void TextRPGCore::Start()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	MainPlayer.SetName("MainPlayer");
	MainPlayer.BeginPlay();

	World.ZoneInit();
	World.PlayerZonePlay();

}
