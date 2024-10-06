#include <iostream>

//��¶�� �θ��� �Լ��� ��ӵȴ�. virtual �� �뵵��? 
//virtual�� ������� ������: �θ� Ŭ������ �Լ��� ȣ���.
//virtual�� ����ϸ� : �ڽ� Ŭ�������� �����ǵ� �Լ��� ȣ���(������).

class StatusUnit
{
public:
	void StatusRender()
	{
		std::cout << "Status Render" << std::endl;
	}
	virtual int GetAtt()//virtual �� ����ϸ�-> �������� �ȴ�.
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
	// �ڽ� Ŭ�������� �� Damage �Լ��� �������Ͽ� ȣ�� ����
	// �θ��� ������ �Ǵ� �����ڸ� ����ص� �ڽ� Ŭ������ �Լ��� ȣ���
	//�ڽ� �ڷ����� �θ��ڷ����� �Ǵ°�(��ĳ����),�Ͻ��� ����ȯ.���� ���
	void Damage(FightUnit& _AttUnit)
	{
		int Value = _AttUnit.GetAtt(); // �θ��� �����ڸ� ����� �θ� �Լ� ȣ��
		HP -= Att;// �θ� Ŭ������ ���� ���
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
	//��ĳ����, �ٿ�ĳ����
	Player player;
	Monster monster;

	//
	FightUnit& Unit = player;
	int playerAtt = Unit.GetAtt();

	//������
	monster.Damage(Unit);
	player.Damage(monster);

}
