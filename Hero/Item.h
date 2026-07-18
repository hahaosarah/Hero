#pragma once

#include <iostream>
#include <string>

//Item 구조체 정의
struct Item
{
	std::string name;
	int price = 0;

	void PrintInfo() const;
	
};