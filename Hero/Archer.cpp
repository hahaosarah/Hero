#include <iostream>
#include <string>
#include "Archer.h"
#include "Monster.h"

using namespace std;

void Archer::attack(Monster* monster)
{
	int damage = getPower()/3 - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	for (int i = 0; i < 3; i++)
	{
		monster->takeDamage(damage);
	}

	cout << "* Shoots an arrow! -> " << damage << " damage to " << monster->getName() << "! (x3)" << endl;
}
