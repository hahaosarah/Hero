#pragma once

#include <iostream>
#include <string>

class Player
{ 
protected:
	std::string name;
	std::string job;
	int level;
	int hp;
	int mp;
	int power;
	int defence;
	int exp;
	int maxExp;

public:
	Player(std::string name, int hp, int mp, int power, int defence);


	virtual void attack() = 0;
	void printPlayerStatus();
	virtual ~Player();
	void takeDamage(int damage);

	int getHp();
	void setHp(int value);
	int getMp();
	void setMp(int value);
	int getPower();
	void setPower(int value);
	int getDefence();
	void setDefence(int value);

};

