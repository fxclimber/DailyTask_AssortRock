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

}

bool UZone::Connecting(UZone* _LinkZone)
{

}

bool UZone::IsConnecting(UZone* _LinkZone)
{

}

void UZone::ConnectingPrint()
{

}

UZone* UZone::ConnectingProgress()
{

}
