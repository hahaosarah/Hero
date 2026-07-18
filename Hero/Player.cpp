#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

//Player 생성자
Player::Player(std::string name, int hp, int mp, int power, int defence)
	: name(name),
	job("Unknown"),
	level(1),
	hp(hp),
	mp(mp),
	power(power),
	defence(defence)
	//생성자에서는 모든 멤버 변수에 초기값을 넣어준다
{
}

//Player 소멸자
Player::~Player()
{
}


//printPlayerStatus 함수
void Player::printPlayerStatus()
{
	cout << "==========================================" << endl;
	cout << "Name: " << name << " | Job: " << job << " | Lv." << level << endl;
	cout << "HP: " << hp << " | MP: " << mp << " | Attack: " << power << " | Defense: " << defence << endl;
	cout << "==========================================" << endl;
}


//takeDamage 함수
void Player::takeDamage(int damage)
{
	int realDamage = damage - defence;

	if (realDamage <= 0)
	{
		realDamage = 1;
	}
	int newHp = hp - realDamage;
	setHp(newHp);
}


//getter/setter
int Player::getHp()
{
	return hp;
}
void Player::setHp(int value)
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

int Player::getMp()
{
	return mp;
}
void Player::setMp(int value)
{
	if (value < 0)
	{
		mp = 0;
	}
	else
	{
		mp = value;
	}
}

int Player::getPower()
{
	return power;
}
void Player::setPower(int value)
{
	if (value < 0)
	{
		power = 0;
	}
	else
	{
		power = value;
	}
}

int Player::getDefence()
{
	return defence;
}
void Player::setDefence(int value)
{
	if (value < 0)
	{
		defence = 0;
	}
	else
	{
		defence = value;
	}
}
