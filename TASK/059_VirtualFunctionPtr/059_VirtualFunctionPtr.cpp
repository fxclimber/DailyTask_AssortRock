#include <iostream>

class FightUnit
{
public:
    virtual int GetAtt()
    {
        return 0;
    }

    virtual int StatusRender()
    {
        return 0;
    }

    int Value = 0;
    
    FightUnit()
        :Value(100)
    {
        //�������Լ��� ȣ��ɶ�,�� ��ü�� �����ɶ� vftable�� ���������.
        this;
    }
};

class Player : public FightUnit
{
public:
    void TestFunc()
    {

    }
    int GetAtt()
    {
        return 0;
    }
    Player()
        :FightUnit()
    {
        Value = 20;
        this;
    }

};


int main()
{
   // Player player;
    Player newPlayer = Player();
    int size = sizeof(Player);

    int a = 0;



}
