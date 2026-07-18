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


public:
	Monster(std::string name, int hp, int power, int defence, std::string dropItemName, int dropItemPrice)
		: name(name),
		hp(hp),
		power(power),
		defence(defence),
		dropItemName(dropItemName),
		dropItemPrice(dropItemPrice)
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

	
	
	//takaDamage 함수 선언
	void takeDamage(int damage);

	//attack 함수 선언
	void attack(Player* player);

	//setHp 함수 선언
	void setHp(int value);

};

