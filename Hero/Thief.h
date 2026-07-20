#pragma once

#include <iostream>
#include <string>
#include "Player.h"

class Thief : public Player
{
public:
	Thief(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power + 30, defence, hp, mp)
	{
		job = "Rogue";
	}

	void attack(Monster* monster) override;
};
