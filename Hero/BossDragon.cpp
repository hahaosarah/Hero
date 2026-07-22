#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "BossDragon.h"

using namespace std;

BossDragon::BossDragon()
	: Monster("Boss Dragon", 200, 60, 20, "Dragon Scale", 1000, 100)
{
}