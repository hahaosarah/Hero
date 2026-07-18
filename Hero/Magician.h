#pragma once

#include <iostream>
#include <string>
#include "Player.h"

class Magician : public Player
{
public:
	Magician(std::string name, int hp, int mp, int power, int defence)
		: Player(name, hp, mp, power, defence)
	{
		job = "Mage";
		setMp(getMp() + 30);
	}

	void attack() override;
};
