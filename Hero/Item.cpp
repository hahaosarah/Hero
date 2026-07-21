#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

bool compareByPrice(const Item& a, const Item& b)
{
	return a.price < b.price;
}


void Item::PrintInfo() const

{
	cout << name << " (" << price << "G)" << endl;
}
