#include "FightZone.h"
#include "Monster.h"
#include "Player.h"
#include <conio.h>
#include "Goblin.h"
#include "Orc.h"
#include "TextRPGCore.h"
#include <BaseSystem/EngineDebug.h>
#include <iostream>

void UFightZone::CreateMonster()
{
	switch (MonsterType)
	{
	case Enums::MONSTERTYPE::GOBLIN:
	{
		CurMonster = new AGoblin();
		break;
	}
	case Enums::MONSTERTYPE::ORC:
		CurMonster = new AOrc();
		break;
	default:
		break;
	}
	//������ ���ε��ִ� �Լ�, 
	//monster -> actor -> fightunit(init) : statusunit���ڸ� ThisUnit���� 
	CurMonster->BeginPlay();
}

UZone* UFightZone::InPlayer()
{
	//���� Ÿ���� ������,���
	if (Enums::MONSTERTYPE::NONE == MonsterType)
	{
		MSGASSERT("���� Ÿ���� ������������ �����");
		return nullptr;
	}

	//�Է�
	InMsgPrint();
	_getch();

	// Ű�Է¿� ���� ���������� �����Ϳ� �ֱ�
	CreateMonster();
	APlayer& Player = TextRPGCore::GetPlayer();
	AMonster& Monster = *CurMonster;
	
	Fight(Player, Monster);//���⼭ �����Լ� ȣ��

	//���� ����
	if (nullptr != CurMonster)
	{
		delete CurMonster;
		CurMonster = nullptr;
	}
	//������ , �׳� �����̵�, zone�� index�� �־��
	return GetZone(0);//�ʺ�����
}

void UFightZone::DamageRender(UObject* _Att, UObject* _Def, int _Damage)
{
	std::cout << _Att->GetName() << "��" << _Def->GetName() << "����" << _Damage << "�� �������� �־���" << std::endl;

}

void UFightZone::Fight(AActor& _Left, AActor& _Right)
{
	//damageLogic , render ȣ�� 
	while (true)
	{
		//����_Left �÷��̾� _Right
		system("cls");
		_Left.StatusRender();
		_Right.StatusRender();
		_getch();

		//���Ͱ� �޴� ������
		_Right.DamageLogic(_Left);
		DamageRender(&_Left, &_Right, _Right.GetDamageValue());
		_getch();

		if (_Right.IsDeath())//���Ͱ� ������
		{
			std::cout << _Left.GetName()/*�÷��̾�*/ << "�� �¸�" << std::endl;
			_Left.SetGold(_Left.GetGold() + _Right.GetGold());//�÷��̾� ���ȹ��
			_getch();
			break;
		}

		//�÷��̾ �޴� ������
		_Left.DamageLogic(_Right);
		DamageRender(&_Right, &_Left, _Left.GetDamageValue());
		_getch();

		if (_Left.IsDeath())
		{
			std::cout << _Right.GetName() << "�� �¸��߽��ϴ�" << std::endl;
			_Right.SetGold(_Right.GetGold() + _Right.GetGold());
			_getch();
			break;
		}
	}
}

