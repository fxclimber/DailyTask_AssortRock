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
//class Monster;//전방선언1//나두 전방선언 할래.
	//Monster* newMonster;

	//class Monster* newMonster;
	//class Monster& newMon;//전방선언2
	Item* weapon;

};

