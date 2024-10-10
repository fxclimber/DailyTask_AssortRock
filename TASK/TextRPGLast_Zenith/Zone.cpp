#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "에 입장했다 \n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "에 체류중이다 \n";
}

bool UZone::InterConnecting(UZone* _LinkZone)
{
	_LinkZone->Connecting(this);//나와 인자를 연결
	this->Connecting(_LinkZone);//인자와 나를 연결
	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("자신을 자신에게 연결시도했다")
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("이미 연결된 지역에 연결 시도했다");
	}
	//맵최대갯수만큼 순회하며, 연결지역배열에 저장
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i])
		{
			ConnectingZones[i] = _LinkZone;//인자를 연결지역배열에 넣어라
			SelectMax += 1;
			return true;
		}
	}
	MSGASSERT("이미 모든 연결이 된 지역이라 연결에 실패");
	return false;
}

bool UZone::IsConnecting(UZone* _ConnectingZone)
{
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (_ConnectingZone == ConnectingZones[i])
		{
			return true;
		}
	}
	return false;

}

UZone* UZone::ConnectingProgress()
{
	while (true)
	{
		ConnectingPrint();
		int Select = _getch();//키입력을 받는 윈도우 함수
	}
}

void UZone::ConnectingPrint()
{
	system("cls");
	int StartIndex = 1;

	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr!= ConnectingZones[i]->GetName())
		{
			//인덱스번호. 마을 이름으로 이동
			const char* NamePtr = ConnectingZones[i]->GetName();
			printf_s("%d %s 로 이동 \n", StartIndex, NamePtr);
			StartIndex++;
		}
	}
	printf_s("%d %s 로 돌아간다 \n", StartIndex , GetName());
	//얘 마지막에 왜있지..?
}

