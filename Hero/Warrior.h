#pragma once

#include <iostream>
#include <string>
#include "Player.h"


class Warrior : public Player
{
public:
	Warrior(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		job = "Warrior";
		setHp(getHp() + 30);
	}

	void attack(Monster* monster) override;

};


