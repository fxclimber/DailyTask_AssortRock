#include "Town.h"
#include "Player.h"
#include "BlackSmith.h"
#include "TextRPGCore.h"
#include "TextRPGCore.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>
#include <iostream>


UTown::UTown()
{
	BS.setParent(this);
}

UZone* UTown::InPlayer()
{
	InMsgPrint();

	APlayer& _Player = TextRPGCore::GetPlayer();

	while (true)
	{
		system("cls");
		ZonePrint();

		_Player.StatusRender();

		std::cout << "0. ü��ȸ�� \n";
		std::cout << "1. ��ȭ \n";
		std::cout << "2. �ٸ� �����̵� \n";

		int Select = _getch();

		switch (Select)
		{
		case '1':
		{
			BS.InPlayer();
			break;
		}
		case '2':
		{
			if (false == IsConnectEmpty())
			{
				UZone* NextZone = ConnectingProgress();
				return NextZone;
			}
			else
			{
				MSGASSERT("���� ���� ����");
				return nullptr;
			}
			break;
		}
		case '0':
		case '3':
			printf_s("���� �̿ϼ�");
			_getch();
			return nullptr;

		default:
			break;
		}

	}

}