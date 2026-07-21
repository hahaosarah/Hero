#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "PotionRecipe.h"


class AlchemyWorkshop
{
private:
	std::vector<PotionRecipe> recipes;
	std::map<std::string, int> potionStock_; // map: 이름표가 붙은 보관함
	const int MAX_STOCK = 3;

public:
	AlchemyWorkshop();

	void ShowAllRecipes();
	void SearchByName(std::string name);
	void SearchByIngredient(std::string ingredient);
	void DispensePotion(const std::string& name);
	void ReturnPotion(const std::string& name);
	int GetStock(const std::string& name);

};
