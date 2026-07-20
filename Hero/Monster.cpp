#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"

using namespace std;

//attack 함수
void Monster::attack(Player* player)
{
	player->takeDamage(power);
}


void Monster::setHp(int value)
{
	if (value < 0)
	{
		hp = 0;
	}
	else
	{
		hp = value;
	}
}


//takeDamage 함수
void Monster::takeDamage(int damage)
{
	int newHp = hp - damage;
	setHp(newHp);
}