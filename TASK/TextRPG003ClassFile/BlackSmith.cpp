#include "BlackSmith.h"
#include "Player.h"
#include <BaseSystem/EngineDebug.h>
#include <conio.h>

void BlackSmith::InPlayer(class UPlayer& _Player/*, int& Result*/)
{
	if (nullptr == ParentZone)
	{
		MSGASSERT("�θ����� ���õ��� �ʾҽ��ϴ�");
		return;
	}

	_Player.SetGold(1000000);

	srand(time(nullptr));

	while (true)
	{
		system("cls");
		_Player.StatusRender();
		std::cout << "1. ��ȭ\n";
		std::cout << "2. ������\n";


		int Select = _getch();
		switch (Select)
		{
		case '1':
		{
			Enhance(_Player);
			break;
			// Ȯ���� ���δ� 2���� 1
			// 1���� �𿩾� �Ѵ�. �÷��̾��� ��ȭ �ܰ� * 100
			// ���� ���� 5���� �����ϰ� �ִ�. �׷��� 500���� �￩�� �Ѵ�.
			// 1~5������ ���а� ����Ȯ���� ������.
			// �ٿ������ �ʴ´�.
			// 6~10������ �����ϸ� 1�� �ٿ�ȴ�.
			// 10~15�� 0���� �����ϸ� 0���� ��������.
			// 15�� �̻��̸� ��ȭ�� ���ϰ� �ؾ����Ѵ�.
		}
		case '2':
			return;
		default:
			break;
		}
	}
}

void BlackSmith::Enhance(class UPlayer& _Player)
{	//Ȯ��
	int randNum = rand();
	randNum %= 2;
	//�ܰ�
	int gold = _Player.GetGold();

		if (randNum == 0)
		{
			gold -= 100 * Level;
			_Player.SetGold(gold);

			std::cout << "��ȭ����" << "-" << Level << "Level" << std::endl;
			Level++;
		}
		else
		{
			std::cout << "��ȭ����" << std::endl;
		}
		_getch();
}
