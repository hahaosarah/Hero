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
	int realDamage = damage - defence;

	if (realDamage <= 0)
	{
		realDamage = 1;
	}
	int newHp = hp - realDamage;
	setHp(newHp);
}