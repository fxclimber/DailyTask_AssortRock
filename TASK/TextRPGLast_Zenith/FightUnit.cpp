#include "FightUnit.h"
#include "StatusUnit.h"
#include<iostream>


void UFightUnit::DamageLogic(UFightUnit& _Unit)
{
    //내가 데미지 받는 함수
    UStatusUnit* Def = this->ThisUnit;//내가 방어자
    UStatusUnit* Att = _Unit.ThisUnit;

    PrevDamage = _Unit.GetDamage();
    int CurHp = Def->GetHp() - PrevDamage;
    Def->SetHp(CurHp);
}

int UFightUnit::GetDamage() const
{
    //min~max사이의 숫자가 리턴되는 함수
    return ThisUnit->GetMinAtt() + (rand() % (ThisUnit->GetMaxAtt() - ThisUnit->GetMinAtt() + 1));
}

bool UFightUnit::IsDeath() const
{
    return  0 >= ThisUnit->GetHp();
}
