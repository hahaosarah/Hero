#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Slime.h"

using namespace std;

Slime::Slime()
	: Monster("Slime", 30, 15, 5, "Slime Jelly", 100, 30)
{
}