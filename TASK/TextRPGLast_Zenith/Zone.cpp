#include "Zone.h"
#include <iostream>
#include <BaseSystem/EngineDebug.h>
#include <conio.h>


void UZone::InMsgPrint()
{
	system("cls");
	std::cout << GetName() << "�� �����ߴ� \n";
}

void UZone::ZonePrint()
{
	std::cout << GetName() << "�� ü�����̴� \n";
}

bool UZone::InterConnecting(UZone* _LinkZone)
{
	_LinkZone->Connecting(this);//���� ���ڸ� ����
	this->Connecting(_LinkZone);//���ڿ� ���� ����
	return true;
}

bool UZone::Connecting(UZone* _LinkZone)
{
	if (this == _LinkZone)
	{
		MSGASSERT("�ڽ��� �ڽſ��� ����õ��ߴ�")
		return false;
	}

	if (true == IsConnecting(_LinkZone))
	{
		MSGASSERT("�̹� ����� ������ ���� �õ��ߴ�");
	}
	//���ִ밹����ŭ ��ȸ�ϸ�, ���������迭�� ����
	for (size_t i = 0; i < static_cast<int>(Enums::MAXS::ZONELINKMAX); i++)
	{
		if (nullptr == ConnectingZones[i])
		{
			ConnectingZones[i] = _LinkZone;//���ڸ� ���������迭�� �־��
			SelectMax += 1;
			return true;
		}
	}
	MSGASSERT("�̹� ��� ������ �� �����̶� ���ῡ ����");
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
		int Select = _getch();//Ű�Է��� �޴� ������ �Լ�
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
			//�ε�����ȣ. ���� �̸����� �̵�
			const char* NamePtr = ConnectingZones[i]->GetName();
			printf_s("%d %s �� �̵� \n", StartIndex, NamePtr);
			StartIndex++;
		}
	}
	printf_s("%d %s �� ���ư��� \n", StartIndex , GetName());
	//�� �������� ������..?
}

