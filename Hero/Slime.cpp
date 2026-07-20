#include <iostream>
#include <string>
#include "Player.h"
#include "Monster.h"
#include "Slime.h"

using namespace std;

Slime::Slime()
	: Monster("Slime", 30, 20, 10, "Slime Jelly", 100, 30)
{
}