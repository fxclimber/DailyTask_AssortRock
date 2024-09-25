#include <iostream>


class Player
{
public:
    Player();
    ~Player();

    void CreateWeapon(){}
    void Attack(){}
    void Die(){}

    int& GetHp() { return Hp; }
    int& GetAtt() { return Att; }

public:
    const char* name = "Knight";//8

    int Def = 7;//4
    int Att = 8;//4
    short check = 30;//2
    bool win = false;//1
    int level = 0;//4
    __int64 exp = 0;//8
    int Hp2 = 200;


private:
    int Hp = 100;//4

};



int main()
{
    //객체 생성
    //Player newPlayer1 = Player();
    //Player newPlayer2 = Player();

    Player newPlayer1;
    Player newPlayer2;
    
    //객체 크기
    int sizeFunc = sizeof(Player);

    //함수참조 변수
    int& getHp = newPlayer1.GetHp();
    int& hp2 = newPlayer1.Hp2;
    //강제 형변환한 주소값
    __int64 Add1 = reinterpret_cast<__int64>(&getHp);
    __int64 Add2 = reinterpret_cast<__int64>(&hp2);



    int a = 0;

    return  0;
}

Player::Player()
{
}

Player::~Player()
{
}
