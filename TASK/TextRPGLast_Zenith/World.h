#pragma once
#include "Town.h"
#include "FightZone.h"


//모든 맵의 관리자, 지도 //UZone 관리자

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

