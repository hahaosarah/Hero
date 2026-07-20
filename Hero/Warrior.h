#pragma once

#include <iostream>
#include <string>
#include "Player.h"


class Warrior : public Player
{
public:
	Warrior(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp + 30, mp, power, defence, hp + 30, mp)
	{
		job = "Warrior";
	}

	void attack(Monster* monster) override;

};


