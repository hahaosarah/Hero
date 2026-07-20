#pragma once

#include <iostream>
#include <string>
#include "Player.h"

class Magician : public Player
{
public:
	Magician(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp + 30, power, defence, hp, mp + 30)
	{
		job = "Mage";
	}

	void attack(Monster* monster) override;
};
