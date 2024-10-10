#pragma once
#include "Object.h"
#include "Enums.h"


class UZone : public UObject
{
public:
	void InMsgPrint();//메세지프린트
	void ZonePrint();//맵초기화
	
	//맵연결 함수들 (중요)
	bool InterConnecting(UZone& _LinkZone)
	{
		return InterConnecting(&_LinkZone);
	}
	bool InterConnecting(UZone* _LinkZone);
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _ConnectingZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();

	bool IsConnectEmpty()
	{
		return SelectMax == 0;
	}
	int GetSelectMax()
	{
		return SelectMax;
	}


	//자식들 사용할 입장함수,구현내용없어도 되므로,헤더에서 {}
	virtual UZone* InPlayer()
	{
		return nullptr;
	}


protected:
	inline UZone* GetZone(int _index)
	{
		return ConnectingZones[_index];
	}


private:
	//ConnectingZones : zone의 포인터로서, 연결지역들의 배열
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = {nullptr,};//?
	int SelectMax = 0;

};

