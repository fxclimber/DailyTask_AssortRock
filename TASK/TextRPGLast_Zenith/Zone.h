#pragma once
#include "Object.h"
#include "Enums.h"


class UZone : public UObject
{
public:
	void InMsgPrint();//�޼�������Ʈ
	void ZonePrint();//���ʱ�ȭ
	
	//�ʿ��� �Լ��� (�߿�)
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


	//�ڽĵ� ����� �����Լ�,���������� �ǹǷ�,������� {}
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
	//ConnectingZones : zone�� �����ͷμ�, ������������ �迭
	UZone* ConnectingZones[static_cast<int>(Enums::MAXS::ZONELINKMAX)] = {nullptr,};//?
	int SelectMax = 0;

};
