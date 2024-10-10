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
	//여러번 래핑되있는 함수, 
	//monster -> actor -> fightunit(init) : statusunit인자를 ThisUnit으로 
	CurMonster->BeginPlay();
}

UZone* UFightZone::InPlayer()
{
	//몬스터 타입이 없으면,경고
	if (Enums::MONSTERTYPE::NONE == MonsterType)
	{
		MSGASSERT("몬스터 타입이 정해지지않은 사냥터");
		return nullptr;
	}

	//입력
	InMsgPrint();
	_getch();

	// 키입력에 따라 몬스터종류별 포인터에 넣기
	CreateMonster();
	APlayer& Player = TextRPGCore::GetPlayer();
	AMonster& Monster = *CurMonster;
	
	Fight(Player, Monster);//여기서 전투함수 호출

	//몬스터 삭제
	if (nullptr != CurMonster)
	{
		delete CurMonster;
		CurMonster = nullptr;
	}
	//끝나면 , 그냥 마을이동, zone의 index를 넣어라
	return GetZone(0);//초보마을
}

void UFightZone::DamageRender(UObject* _Att, UObject* _Def, int _Damage)
{
	std::cout << _Att->GetName() << "가" << _Def->GetName() << "에게" << _Damage << "의 데미지를 주었다" << std::endl;

}

void UFightZone::Fight(AActor& _Left, AActor& _Right)
{
	//damageLogic , render 호출 
	while (true)
	{
		//몬스터_Left 플레이어 _Right
		system("cls");
		_Left.StatusRender();
		_Right.StatusRender();
		_getch();

		//몬스터가 받는 데미지
		_Right.DamageLogic(_Left);
		DamageRender(&_Left, &_Right, _Right.GetDamageValue());
		_getch();

		if (_Right.IsDeath())//몬스터가 죽으면
		{
			std::cout << _Left.GetName()/*플레이어*/ << "이 승리" << std::endl;
			_Left.SetGold(_Left.GetGold() + _Right.GetGold());//플레이어 골드획득
			_getch();
			break;
		}

		//플레이어가 받는 데미지
		_Left.DamageLogic(_Right);
		DamageRender(&_Right, &_Left, _Left.GetDamageValue());
		_getch();

		if (_Left.IsDeath())
		{
			std::cout << _Right.GetName() << "이 승리했습니다" << std::endl;
			_Right.SetGold(_Right.GetGold() + _Right.GetGold());
			_getch();
			break;
		}
	}
}

