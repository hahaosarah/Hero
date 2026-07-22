#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Orc.h"

using namespace std;

Orc::Orc()
	: Monster("Orc", 80, 35, 15, "Orc Club", 500, 80)
{
}