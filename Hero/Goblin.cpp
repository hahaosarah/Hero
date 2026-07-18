#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Goblin.h"

using namespace std;

Goblin::Goblin()
	: Monster("Goblin", 500, 999, 30, "Goblin Fang", 1000)
{
}