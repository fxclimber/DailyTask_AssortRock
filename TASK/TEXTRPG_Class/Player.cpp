#include "Player.h"
#include "Item.h"
#include "Monster.h"


//Player::Player()
//{
//}
//
//Player::~Player()
//{
//}
//
void Player::equip(Item* weapon)
{
	weapon = nullptr;
	weapon->Test();

}

void Player::getMon(Monster& monster)
{
	monster.IAMMonster();
}
