#include <iostream>

//어쨋건 부모의 함수는 상속된다. virtual 의 용도는? 
//virtual을 사용하지 않으면: 부모 클래스의 함수가 호출됨.
//virtual을 사용하면 : 자식 클래스에서 재정의된 함수가 호출됨(다형성).

class StatusUnit
{
public:
	void StatusRender()
	{
		std::cout << "Status Render" << std::endl;
	}
	virtual int GetAtt()//virtual 을 사용하면-> 다형성이 된다.
	{
		return Att;
	}
protected:
	int Att = 10;
	int HP = 100;
};

class FightUnit : public StatusUnit
{
public:
	// 자식 클래스에서 이 Damage 함수를 재정의하여 호출 가능
	// 부모의 포인터 또는 참조자를 사용해도 자식 클래스의 함수가 호출됨
	//자식 자료형이 부모자료형이 되는것(업캐스팅),암시적 형변환.권장 방법
	void Damage(FightUnit& _AttUnit)
	{
		int Value = _AttUnit.GetAtt(); // 부모의 참조자를 사용해 부모 함수 호출
		HP -= Att;// 부모 클래스의 변수 사용
	}
};

class Monster : public FightUnit
{
public:
	void Statusrender()
	{
		std::cout << "Player Status Render" << std::endl;
	}

};

class Player : public FightUnit
{
public:
	void StatusRender()
	{
		std::cout << "Player Status Render" << std::endl;
	}

	int GetAtt()override
	{
		return StatusUnit::GetAtt() + EquipAtt;
	}

	int EquipAtt = 5;
};


int main()
{
	//업캐스팅, 다운캐스팅
	Player player;
	Monster monster;

	//
	FightUnit& Unit = player;
	int playerAtt = Unit.GetAtt();

	//다형성
	monster.Damage(Unit);
	player.Damage(monster);

}
