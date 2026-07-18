#pragma once

#include <iostream>
#include <string>

//PotionRecipe 구조체 정의
struct PotionRecipe
{
	std::string name;
	std::string ingredient1;
	std::string ingredient2;

	void PrintInfo() const;
};
