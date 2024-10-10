#include "FightUnit.h"
#include "StatusUnit.h"
#include<iostream>


void UFightUnit::DamageLogic(UFightUnit& _Unit)
{
    //���� ������ �޴� �Լ�
    UStatusUnit* Def = this->ThisUnit;//���� �����
    UStatusUnit* Att = _Unit.ThisUnit;

    PrevDamage = _Unit.GetDamage();
    int CurHp = Def->GetHp() - PrevDamage;
    Def->SetHp(CurHp);
}

int UFightUnit::GetDamage() const
{
    //min~max������ ���ڰ� ���ϵǴ� �Լ�
    return ThisUnit->GetMinAtt() + (rand() % (ThisUnit->GetMaxAtt() - ThisUnit->GetMinAtt() + 1));
}

bool UFightUnit::IsDeath() const
{
    return  0 >= ThisUnit->GetHp();
}
