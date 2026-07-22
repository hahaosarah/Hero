#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <map>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
#include "Slime.h"
#include "Goblin.h"
#include "Item.h"
#include "AlchemyWorkshop.h"
#include "PotionRecipe.h"
#include "Inventory.h"
#include "Orc.h"
#include "BossDragon.h"

using namespace std;

void printStatus(string name, int stat[]);
bool enterDungeon(Player* player, string name, string jobName, Inventory<Item>& inventory, int maxInventorySize, int& clearedRoomCount);
void showInventory(Inventory<Item>& inventory, int maxInventorySize);
bool checkGameOver(Player* player);
void handleVictory(Monster* monster, Player* player, Inventory<Item>& inventory, int maxInventorySize);
void showPotionShopMenu();
void setPotion(int count, int* hpPotion, int* mpPotion);
void choosePlayerAction(Player* player, Monster* monster, Inventory<Item>& inventory, int maxInventorySize);

//main 함수
int main()
{
	int clearedRoomCount = 0;

	//inventory 선언
	Inventory<Item> inventory;
	/*vector<Item> inventory;*/
	inventory.AddItem({ "HP Potion", 50 });
	inventory.AddItem({ "MP Potion", 50 });

	cout << "===============================================" << endl;
	cout << "                 [ Hello Hero ]                " << endl;
	cout << "===============================================" << endl;
	string name;
	cout << "Enter your hero's name: ";
	cin >> name;


	const int SIZE = 4;
	int stat[SIZE] = { 0 };


	//HP MP 50이상 입력 받기 반복문
	while (true)
	{
		cout << "Enter HP and MP: ";
		cin >> stat[0] >> stat[1];
		if (stat[0] >= 50 && stat[1] >= 50)
		{
			break;
		}
		cout << "HP or MP is too low. Try again." << endl;
	}


	//Attack Defense 50이상 입력 받기 반복문
	while (true)
	{
		cout << "Enter Attack and Defense: ";
		cin >> stat[2] >> stat[3];
		if (stat[2] >= 50 && stat[3] >= 50)
		{
			break;
		}
		cout << "Attack or Defense is too low. Try again." << endl;
	}


	printStatus(name, stat);
	// printStatus(name, stat); 호출

	int hpPotion;
	int mpPotion;

	setPotion(5, &hpPotion, &mpPotion);

	int choice = 0;
	bool isGameStart = false;


	cout << "* you received 5 HP Potions and 5 MP Potions." << endl;
	cout << "=============================================" << endl;
	cout << "< Character Upgrade >" << endl;
	cout << "1. HP UP";
	cout << "  ";
	cout << "2. MP UP";
	cout << "  ";
	cout << "3. Attack x2" << endl;

	cout << "4. Defense x2";
	cout << "  ";
	cout << "5. Show Stats";
	cout << "  ";
	cout << "0. Start Game" << endl;
	cout << "==============================================" << endl;

	//Game Start
	while (!isGameStart)
	{
		cout << "Choose: ";
		cin >> choice;


		//1.HP  2.MP  3.Attack  4.Defense  5.Show Stats  0.Start Game
		switch (choice)
		{
		case 1:
			if (hpPotion > 0)
			{
				stat[0] += 20;
				hpPotion -= 1;
				cout << "* HP increased by 20. (HP Potion used: ";
				cout << hpPotion;
				cout << " left)" << endl;
			}
			else
			{
				cout << "* Not enough HP Potions." << endl;
			}
			break;

		case 2:
			if (mpPotion > 0)
			{
				stat[1] += 20;
				mpPotion -= 1;
				cout << "* MP increased by 20. (MP Potion used: ";
				cout << mpPotion;
				cout << " left)" << endl;
			}
			else
			{
				cout << "* Not enough MP Potions." << endl;
			}
			break;

		case 3:
			stat[2] *= 2;
			cout << "Attack power doubled." << endl;
			break;

		case 4:
			stat[3] *= 2;
			cout << "Defense power doubled." << endl;
			break;

		case 5:
			printStatus(name, stat);
			break;

		case 0:
			cout << "Starting the game!" << endl;
			isGameStart = true;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}

	cout << "   " << endl; 
	cout << "===============================================" << endl;
	cout << "                [ Job Selection ]              " << endl;
	cout << "===============================================" << endl;
	cout << name << ", choose your job!" << endl;
	cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;

	int jobchoice = 0;
	string jobName = "  ";

	Player* player = nullptr;

	while (player == nullptr)
	{
		cout << "Choose: ";
		cin >> jobchoice;


		//Warrior
		if (jobchoice == 1)
		{
			jobName = "Warrior";
			player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
			cout << "* You became a Warrior! (HP +30)" << endl;
		}

		//Mage
		else if (jobchoice == 2)
		{
			jobName = "Mage";
			player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
			cout << "* You became a Mage! (MP +30)" << endl;
		}

		//Rogue
		else if (jobchoice == 3)
		{
			jobName = "Rogue";
			player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
			cout << "* You became a Rogue! (Attack +30)" << endl;
		}

		//Archer
		else if (jobchoice == 4)
		{
			jobName = "Archer";
			player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
			cout << "* You became an Archer! (Defense +30)" << endl;
		}

		//Invalid choice
		else
		{
			cout << "Invalid choice!" << endl;
		}
	}
	


	


	int Menuchoice = 0;
	const int maxInventorySize = 10;
	bool isRunning = true;


	// Main Menu
	while (isRunning)
	{
		cout << "   " << endl;
		cout << "============= Main Menu =============" << endl;
		cout << "1. Enter Dungeon" << endl;
		cout << "2. Check Inventory" << endl;
		cout << "3. Potion Shop" << endl;
		cout << "0. Quit" << endl;
		cout << "  " << endl;
		cout << "Choose:" << endl;
		cin >> Menuchoice;


		switch (Menuchoice)
		{
		case 1:
		{
			bool isGameOver = enterDungeon(player, name, jobName, inventory, maxInventorySize, clearedRoomCount);

			if (isGameOver)
			{
				isRunning = false;
			}

			break;
		}

		case 2:
		{
			showInventory(inventory, maxInventorySize);
			break;
		}
		
		case 3:
		{
			showPotionShopMenu();
			break;
		}

		case 0:
		{
			isRunning = false;
			break;
		}
			

		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
			
		}


	}


	
	//플레이어 객체를 메모리에서 제거
	if (player != nullptr)
	{
		player->printPlayerStatus();

		delete player;
		player = nullptr;
	}
	

	return 0;

}



//printStatus 함수 정의
void printStatus(string name, int stat[])
{
	// 상태창 출력
	cout << "===============================================" << endl;
	cout << "           " << name << "'s Status                 " << endl;
	cout << "===============================================" << endl;
	cout << "           HP: " << stat[0];
	cout << "         MP: " << stat[1];
	cout << "               " << endl;

	cout << "        Attack: " << stat[2];
	cout << "     Defense: " << stat[3];
	cout << "            " << endl;
	cout << "===============================================" << endl;
}


//Enter Dungeon 함수 정의
bool enterDungeon(Player* player, string name, string jobName, Inventory<Item>& inventory, int maxInventorySize, int& clearedRoomCount)
{
	Slime slime;
	Goblin goblin;
	Orc orc;
	BossDragon bossDragon;

	Monster* monster = nullptr;
	vector<Monster*> monsterRooms = { &slime, &goblin, &orc, &bossDragon };

	cout << "      " << endl;
	cout << "===============================================" << endl;
	cout << "              [ Dungeon Floor 1 ]              " << endl;
	cout << "===============================================" << endl;

	
	
	if (clearedRoomCount >= 0&& clearedRoomCount < monsterRooms.size())
	{
		monster = monsterRooms[clearedRoomCount];
	}
	else
	{
		cout << "Invalid monster choice!" << endl;
		return false;
	}
	
	

	//Player VS Monster
	if (player != nullptr && monster != nullptr)
	{

		cout << "[ Battle Start! ] " << name << "(" << jobName << ")" << " vs " << monster->getName() << endl;
		cout << "         " << endl;
		int monsterStartHp = monster->getHp();

		while (player->getHp() > 0 && monster->getHp() > 0)
		{

			cout << " ----------  Player Turn ---------- " << endl;

			int beforeMonsterHp = monster->getHp();
			
			choosePlayerAction(player, monster, inventory, maxInventorySize);

			int afterMonsterHp = monster->getHp();

			cout << monster->getName() << " HP: " << beforeMonsterHp << " -> " << afterMonsterHp;


			// if Monster Dead
			if (afterMonsterHp <= 0)
			{
				cout << " (Dead)";
			}

			cout << endl;

			if (monster->getHp() <= 0)
			{
				handleVictory(monster, player, inventory, maxInventorySize);
				cout << "Room " << clearedRoomCount + 1 << ": " << monster->getName() << "   (HP " << monsterStartHp << ", Attack "<< monster->getPower() << ")     -> Clear!" << endl;

				if (clearedRoomCount == 3)
				{
					cout << "===============================================" << endl;
					cout << "                 GAME CLEAR!                   " << endl;
					cout << "===============================================" << endl;
					return true;
				}

				clearedRoomCount++;

				if (clearedRoomCount == 3)
				{
					cout << "★ Boss Room Unlocked!" << endl;
				}

				return false;
			}


			cout << "   " << endl;
			cout << " ---------- Monster Turn ---------- " << endl;

			int beforePlayerHp = player->getHp();
			monster->attack(player);
			int afterPlayerHp = player->getHp();

			cout << name << " HP: " << beforePlayerHp << " -> " << afterPlayerHp;


			// if Player Dead
			if (afterPlayerHp <= 0)
			{
				cout << " (Dead)" << endl;
			}
			else
			{
				cout << endl;
			}

			if (checkGameOver(player))
			{
				return true;
			}




		}
	}
	else
	{
		cout << "Battle cannot start." << endl;
	}
	return false;
}


//Show Inventory 함수 정의
void showInventory(Inventory<Item>& inventory, int maxInventorySize)
{
	cout << "    " << endl;
	cout << "===============================================" << endl;
	cout << "    [ Inventory sorted by price (" << inventory.GetSize() << " / " << inventory.GetCapacity() << ") ] " << endl;
	cout << "===============================================" << endl;
	if (inventory.IsEmpty())
	{
		cout << "Inventory is empty." << endl;
	}
	
	else
	{
		inventory.SortItems();
		inventory.ShowInventory();
	}
}


//Game Over 함수 정의
bool checkGameOver(Player* player)
{
	if (player != nullptr && player->getHp() <= 0)
	{
		cout << "★ Defeat..." << endl;
		cout << "(Game Over)" << endl;
		cout << "Please restart the program to play again." << endl;

		return true;
	}

	return false;
}


//Victory 함수 정의
void handleVictory(Monster* monster, Player* player, Inventory<Item>& inventory, int maxInventorySize)
{
	if (monster != nullptr && monster->getHp() <= 0)
	{
		cout << "★ Victory!" << endl;

		if(player != nullptr)
		{
			player->gainExp(monster->getExpReward());
		}

		cout << "  -> Got: " << monster->getDropItemName() << "!" << endl;

		Item droppedItem;
		droppedItem.name = monster->getDropItemName();
		droppedItem.price = monster->getDropItemPrice();

		inventory.AddItem(droppedItem);
		cout << " -> Saved to inventory." << endl;
	}
}


//Show Potion Shop 함수 정의
void showPotionShopMenu()
{
	AlchemyWorkshop workshop;
	string searchPotionName;
	string searchIngredient;
	bool potionShopStart = true;


	while (potionShopStart)
	{
		int potionChoice = 0;

		cout << "===============================================" << endl;
		cout << "                 [ Potion Shop ]               " << endl;
		cout << "===============================================" << endl;
		cout << endl;
		cout << "1. Show all recipes" << endl;
		cout << "2. Search by potion name" << endl;
		cout << "3. Search by ingredient" << endl;
		cout << "4. Check potion stock" << endl;
		cout << "5. Dispense potion" << endl;
		cout << "6. Return potion" << endl;
		cout << "0. Go Back" << endl;
		cout << endl;
		cout << "Choose: ";

		cin >> potionChoice;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}

		switch (potionChoice)
		{
		case 1:
		{
			workshop.ShowAllRecipes();
			break;
		}
			

		case 2:
		{
			cout << "Search potion name: ";
			getline(cin >> ws, searchPotionName);
			workshop.SearchByName(searchPotionName);
			break;
		}
			

		case 3:
		{
			cout << "Search ingredient: ";
			getline(cin >> ws, searchIngredient);
			workshop.SearchByIngredient(searchIngredient);
			break;
		}
			

		case 4:
		{
			cout << "Enter potion name to check stock: ";
			getline(cin >> ws, searchPotionName);
			int stock;
			stock = workshop.GetStock(searchPotionName);
			cout << "Stock of " << searchPotionName << ": " << stock << endl;
			break;
		}
			

		case 5:
		{
			cout << "Enter potion name to dispense: ";
			getline(cin >> ws, searchPotionName);
			workshop.DispensePotion(searchPotionName);
			break;
		}
			

		case 6:
		{
			cout << "Enter potion name to return: ";
			getline(cin >> ws, searchPotionName);
			workshop.ReturnPotion(searchPotionName);
			break;
		}
			

		case 0:
		{
			potionShopStart = false;
			break;
		}
			

		default:
		{
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
			
		}
	}





	
}


//Set Potion 함수 정의
void setPotion(int count, int* hpPotion, int* mpPotion)
{
	*hpPotion = count;
	*mpPotion = count;
}


//choose Player Action 함수 정의
void choosePlayerAction(Player* player, Monster* monster, Inventory<Item>& inventory, int maxInventorySize)
{
	if (player == nullptr || monster == nullptr)
	{
		cout << "Error: Player or Monster is null." << endl;
		return;
	}
	
	cout << "1. Attack" << endl;
	cout << "2. Use Item" << endl;	
	cout << "Choose: " << endl;


	int actionChoice = 0;
	cin >> actionChoice;

	switch (actionChoice)
	{
	case 1:
	{
		player->attack(monster);
		break;
	}
	case 2:
	{
		int itemChoice = 0;
		int selectedIndex;
		Item selectedItem;
		int beforeHp;
		int afterHp;
		int beforeMp;
		int afterMp;	
		int recoverAmount;

		if (inventory.IsEmpty())
		{
			cout << "Inventory is empty." << endl;
			break;
		}

		showInventory(inventory, maxInventorySize);

		cout << "Choose item: " << endl;
		cin >> itemChoice;

		if (itemChoice < 1 || itemChoice > inventory.GetSize())
		{
			cout << "Invalid item choice." << endl;
			break;
		}
		
		selectedIndex = itemChoice - 1;
		inventory.GetItemAt(selectedIndex, selectedItem);

		if(selectedItem.name == "HP Potion")
		{
			beforeHp = player->getHp();
			recoverAmount = 50;
			afterHp = min(beforeHp + recoverAmount, player->getMaxHp());
			player->setHp(afterHp);
			cout << "* HP Potion used! HP recovered by " << recoverAmount << ". (" << beforeHp << " -> " << afterHp << ")" << endl;
			inventory.RemoveItemAt(selectedIndex);
		}
		else if(selectedItem.name == "MP Potion")
		{
			beforeMp = player->getMp();
			recoverAmount = 50;
			afterMp = min(beforeMp + recoverAmount, player->getMaxMp());
			player->setMp(afterMp);
			cout << "* MP Potion used! MP recovered by " << recoverAmount << ". (" << beforeMp << " -> " << afterMp << ")" << endl;
			inventory.RemoveItemAt(selectedIndex);
		}
		else
		{
			cout << "* Cannot use this item." << endl;
			break;
		}
		break;
	}

	default:
	{
		cout << "Invalid choice. Please try again." << endl;
		break;
	}
		
		
	}
}