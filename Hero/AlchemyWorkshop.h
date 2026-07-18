#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "PotionRecipe.h"


class AlchemyWorkshop
{
private:
	std::vector<PotionRecipe> recipes;

public:
	AlchemyWorkshop();

	void ShowAllRecipes();
	void SearchByName(std::string name);
	void SearchByIngredient(std::string ingredient);
};
