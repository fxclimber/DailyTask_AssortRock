#pragma once
#include "Town.h"
#include "FightZone.h"


//��� ���� ������, ���� //UZone ������

class UWorld
{
public:
	void ZoneInit();
	void PlayerZonePlay();

	UTown Town0;
	UTown Town1;
	UTown Town2;
	
	UFightZone FZone0;

};

