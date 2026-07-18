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
	bool searchIngredient = false;
	int foundCount = 0;

	for (int i = 0; i < recipes.size(); i++)
	{
		if (recipes[i].ingredient1 == ingredient || recipes[i].ingredient2 == ingredient)
		{
			recipes[i].PrintInfo();
			searchIngredient = true;
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