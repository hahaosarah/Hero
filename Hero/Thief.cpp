#include <iostream>
#include <string>
#include "Thief.h"
#include "Monster.h"

using namespace std;

void Thief::attack(Monster* monster)
{
	int damage = getPower() / 5 - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	for (int i = 0; i < 5; i++)
	{
		monster->takeDamage(damage);
	}

	cout << "* Throws a dagger! -> " << damage << " damage to " << monster->getName() << "! (x5)" << endl;
}
