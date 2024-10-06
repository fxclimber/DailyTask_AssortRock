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
        //생성자함수가 호출될때,즉 객체가 생성될때 vftable이 만들어진다.
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
