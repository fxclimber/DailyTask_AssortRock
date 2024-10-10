#pragma once
#include "Zone.h"
#include "Enums.h"

//ƒ¡≈Ÿ√˜ æ∆≈∞≈ÿ√ƒ
class UFightZone : public UZone
{
public:
	void SetMonsterType(Enums::MONSTERTYPE _MonsterType)
	{
		MonsterType = _MonsterType;
	}

	UZone* InPlayer()override;

	void DamageRender(UObject* _Att, UObject* _Def, int _Damage);

	void Fight(class AActor& _Left, class AActor& _Right);

private:
	int MinMonsterCount = 1;
	int MaxMonsterCount = 1;

	class AMonster* CurMonster;

	Enums::MONSTERTYPE MonsterType = Enums::MONSTERTYPE::NONE;
	void CreateMonster();


};

