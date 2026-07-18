#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

void Item::PrintInfo() const

{
	cout << name << " (" << price << "G)" << endl;
}
