#pragma once

#include <iostream>
#include <string>
#include "Player.h"

class Archer : public Player
{
public:
	Archer(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		job = "Archer";
		setDefence(getDefence() + 30);
	}
	void attack() override;
};

