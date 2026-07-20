#include <iostream>
#include <string>
#include "Magician.h"
#include "Monster.h"

using namespace std;

void Magician::attack(Monster* monster)
{
	int damage = getPower() - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	monster->takeDamage(damage);

	cout << "* Fires a fireball!" << damage << " damage to " << monster->getName() << "!" << endl;
}

