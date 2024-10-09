#include "Town.h"
#include "Player.h"
#include "BlackSmith.h"
#include "TextRPGCore.h"

#include <conio.h>
#include <iostream>


UTown::UTown()
{
	BS.setParent(this);
}

UZone* UTown::InPlayer()
{
	InMsgPrint();

	UPlayer& _Player = TextRPGCore::GetPlayer();

	while (true)
	{
		system("cls");
		ZonePrint();


	}

}
