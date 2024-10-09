#pragma once
#include "Object.h"
#include "Enums.h"


class UZone : public UObject
{
public:
	void InMsgPrint();//메세지프린트
	void ZonePrint();//맵초기화
	
	bool InterConnecting(UZone* _LinkZone);//맵연결 함수들
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();
	virtual UZone* InPlayer()//자식들 사용할 입장함수,구현내용없어도 되므로,헤더에서 {}
	{
		return nullptr;
	}


protected:
	inline UZone* GetZone(int _index)
	{
		return ConnectingZones[_index];
	}


private:
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = {nullptr,};//?
	int SelectIndex = 0;

};

