#include <iostream>


const int NAMELEN = 10;

class StatusUnit
{
protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;
    int Charm = 0;

};

class Item
{

};

class Inventory
{
    Item Arr[100];
};

class FightUnit : public StatusUnit
{
public:
    int GetHp() { return Hp; }

    int GetDamage()const
    {
        int randNum = rand() % (StatusUnit::MaxAtt - StatusUnit::MinAtt + 1) + StatusUnit::MinAtt;

        return randNum;
    }

    // 클래스의 레퍼런스를 넣어주는것이 많은게 간단해 집니다.
    void DamageLogic(const FightUnit& _AttUnit)
    {
        // _AttUnit => 나를 공격하려는 상대
        if (Hp >= 0)
        {
            Hp -= _AttUnit.GetDamage();
        }
        else
        {
            Hp = 0;
        }

    }

    void DamageRender(const char* const _AttName, int _Att)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttName, Name, _Att);
    }

    const char* GetName() const
    {
        return Name;
    }
protected:
    int minDmg = 1;
    int maxDmg = 3;

private:


};

class Player : public FightUnit
{
};

class Monster : public FightUnit
{

};

int main()
{
    int seed = static_cast<__int64>(time(nullptr));
    srand(seed*1212);

    Player NewPlayer;
    Monster NewMonster;

    for (int i = 0; i < 10; i++)
    {
    NewMonster.DamageLogic(NewPlayer);
    int ReadHp = NewMonster.GetHp();
    std::cout << ReadHp << std::endl;
    }

    int a = 0;
}



