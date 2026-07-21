#include <iostream>
#include <string>
#include <vector>
#include "PotionRecipe.h"
#include "AlchemyWorkshop.h"

using namespace std;

//Alchemy Workshop 생성자
AlchemyWorkshop::AlchemyWorkshop()
{
	//HPPotion
	PotionRecipe hpPotion;
	hpPotion.name = "HPPotion";
	hpPotion.ingredient1 = "Herb";
	hpPotion.ingredient2 = "Clear Water";

	recipes.push_back(hpPotion);

	//MPPotion
	PotionRecipe mpPotion;
	mpPotion.name = "MPPotion";
	mpPotion.ingredient1 = "Mana Flower";
	mpPotion.ingredient2 = "Slime Jelly";

	recipes.push_back(mpPotion);

	//StaminaPotion
	PotionRecipe staminaPotion;
	staminaPotion.name = "StaminaPotion";
	staminaPotion.ingredient1 = "Herb";
	staminaPotion.ingredient2 = "Berry";

	recipes.push_back(staminaPotion);

	//AntidotePotion
	PotionRecipe antidotePotion;
	antidotePotion.name = "AntidotePotion";
	antidotePotion.ingredient1 = "Green Mushroom";
	antidotePotion.ingredient2 = "Slime Jelly";

	recipes.push_back(antidotePotion);

	//StrengthPotion
	PotionRecipe strengthPotion;
	strengthPotion.name = "StrengthPotion";
	strengthPotion.ingredient1 = "Goblin Fang";
	strengthPotion.ingredient2 = "Berry";

	recipes.push_back(strengthPotion);
	// 여기서 recipes에 기본 레시피들을 push_back


	potionStock_["HPPotion"] = MAX_STOCK;
	potionStock_["MPPotion"] = MAX_STOCK;
	potionStock_["StaminaPotion"] = MAX_STOCK;
	potionStock_["AntidotePotion"] = MAX_STOCK;
	potionStock_["StrengthPotion"] = MAX_STOCK;
}


//ShowAllRecipes 함수
void AlchemyWorkshop::ShowAllRecipes()
{
	for (int i = 0; i < recipes.size(); i++)
	{
		recipes[i].PrintInfo();
	}
}


//SearchByName 함수
void AlchemyWorkshop::SearchByName(std::string name)
{
	bool searchName = false;

	for (int i = 0; i < recipes.size(); i++)
	{
		if (recipes[i].name == name)
		{
			recipes[i].PrintInfo();
			searchName = true;
		}
	}

	if (searchName == false)
	{
		cout << "Recipe not found." << endl;
	}

}


//SearchByIngredient 함수
void AlchemyWorkshop::SearchByIngredient(std::string ingredient)
{
	int foundCount = 0;

	for (int i = 0; i < recipes.size(); i++)
	{
		if (recipes[i].ingredient1 == ingredient || recipes[i].ingredient2 == ingredient)
		{
			recipes[i].PrintInfo();
			foundCount++;
		}
	}

	if (foundCount == 0)
	{
		cout << "Recipe not found." << endl;
	}
	else
	{
		cout << "Found " << foundCount << " recipes." << endl;
	}
}


//DispensePotion 함수
void AlchemyWorkshop::DispensePotion(const std::string& name)
{
	if (potionStock_.find(name) != potionStock_.end())
	{
		if (potionStock_[name] > 0)
		{
			potionStock_[name]--;
			std::cout << "-> Dispense " << name << " (stock: " << potionStock_[name] << ")" << std::endl;
		}
		else
		{
			std::cout << "-> Dispense failed: out of stock!" << std::endl;
		}
	}
	else
	{
		std::cout << "Potion not found in stock." << std::endl;
	}
}


//ReturnPotion 함수
void AlchemyWorkshop::ReturnPotion(const std::string& name)
{
	if (potionStock_.find(name) != potionStock_.end())
	{
		if (potionStock_[name] < MAX_STOCK)
		{
			potionStock_[name]++;
			std::cout << "-> Return empty bottle  (stock: " << potionStock_[name] << ")" << std::endl;
		}
		else
		{
			std::cout << "Stock for " << name << " is already full." << std::endl;
		}
	}
	else
	{
		std::cout << "Potion not found in stock." << std::endl;
	}
}


//GetStock 함수
int AlchemyWorkshop::GetStock(const std::string& name)
{
	if (potionStock_.find(name) != potionStock_.end())
	{
		return potionStock_[name];
	}
	else
	{
		return 0;
	}
}