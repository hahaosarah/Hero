#include <iostream>
#include <string>
#include <vector>
#include "PotionRecipe.h"

using namespace std;

void PotionRecipe::PrintInfo() const
{
	cout << "-> " << name << ": " << ingredient1 << " x1, " << ingredient2 << " x1" << endl;
}