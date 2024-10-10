#include "TextRPGCore.h"
#include "Player.h"
#include "World.h"
#include <iostream>

//�÷��̾� 1��, �ٸ� ����� ������� ������, ����� ����!
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
