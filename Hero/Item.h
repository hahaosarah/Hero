#pragma once

#include <iostream>
#include <string>

//Item 구조체 정의
struct Item
{
	std::string name;
	int price = 0;

	void PrintInfo() const;
	
	bool operator==(const Item& other) const
	{
		return name == other.name && price == other.price;
	}
};


// compareByPrice 함수 선언
bool compareByPrice(const Item& a, const Item& b);
