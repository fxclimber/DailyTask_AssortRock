#pragma once

class Item;

class Player
{
public:

	Player* returnPlayer(Player* const player)
	{
		this->equip(weapon);
		return player;
	}

	void equip(Item* weapon);
	void getMon(class Monster& monster);


private:
//class Monster;//���漱��1//���� ���漱�� �ҷ�.
	//Monster* newMonster;

	//class Monster* newMonster;
	//class Monster& newMon;//���漱��2
	Item* weapon;

};

