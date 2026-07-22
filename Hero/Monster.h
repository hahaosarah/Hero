#pragma once

#include <iostream>
#include <string>
#include "Player.h"

class Monster
{

	std::string name;
	int hp;
	int power;
	int defence;
	std::string dropItemName;
	int dropItemPrice;
	int expReward;


public:
	Monster(std::string name, int hp, int power, int defence, std::string dropItemName, int dropItemPrice, int expReward)
		: name(name),
		hp(hp),
		power(power),
		defence(defence),
		dropItemName(dropItemName),
		dropItemPrice(dropItemPrice),
		expReward(expReward)
	{
	}

	std::string getName()
	{
		return name;
	}
	
	int getHp()
	{
		return hp;
	}
	
	std::string getDropItemName()
	{
		return dropItemName;
	}
	
	int getDropItemPrice()
	{
		return dropItemPrice;
	}

	int getExpReward()
	{
		return expReward;
	}
	
	int getDefence()
	{
		return defence;
	}

	int getPower()
	{
		return power;
	}
	
	//takeDamage 함수 선언
	void takeDamage(int damage);

	//attack 함수 선언
	void attack(Player* player);

	//setHp 함수 선언
	void setHp(int value);

};

