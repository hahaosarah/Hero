#include <iostream>
#include <string>
#include "Warrior.h"
#include "Monster.h"

using namespace std;

void Warrior::attack(Monster* monster)
{
	int damage = getPower() - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}
	monster->takeDamage(damage);

	cout << "* Swings a sword! -> " << damage << " damage to " << monster->getName() << "!" << endl;
}
