#pragma once
#include "Object.h"
#include "Enums.h"


class UZone : public UObject
{
public:
	void InMsgPrint();//�޼�������Ʈ
	void ZonePrint();//���ʱ�ȭ
	
	bool InterConnecting(UZone* _LinkZone);//�ʿ��� �Լ���
	bool Connecting(UZone* _LinkZone);
	bool IsConnecting(UZone* _LinkZone);
	void ConnectingPrint();

	UZone* ConnectingProgress();
	virtual UZone* InPlayer()//�ڽĵ� ����� �����Լ�,���������� �ǹǷ�,������� {}
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

