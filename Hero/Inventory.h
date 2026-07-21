#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Item.h"

template <typename T>
class Inventory 
{
private:
	std::vector<T> items;

public:
	Inventory() {};
	~Inventory() {};

	//복사 생성자
	Inventory(const Inventory<T>& other)
	{
		items = other.items;
	}

	//복사 대입 연산자
	Inventory<T>& operator=(const Inventory<T>& other)
	{
		if (this != &other)
		{
			items = other.items;
		}
		return *this;
	}




	//AddItem 아이템	추가 함수
	void AddItem(const T& item) 
	{
		items.push_back(item);
	}

	//RemoveItem 아이템 제거 함수
	void RemoveItem(const T& item) 
	{
		auto it = std::find(items.begin(), items.end(), item);
		if (it != items.end()) 
		{
			items.erase(it);
		}
	}

	//ShowInventory 아이템 목록 출력 함수
	void ShowInventory() const
	{
		if (items.empty())
		{
			std::cout << "Inventory is empty." << std::endl;
			return;
		}

		std::cout << "Inventory:" << std::endl;

		int number = 1;

		for (const auto& item : items)
		{
			std::cout << number << ". " << item.name << " (" << item.price << "G)" << std::endl;
			number++;
		}
	}

	//GetSize 아이템 개수 반환 함수
	size_t GetSize() const
	{
		return items.size();
	}

	//IsFull 인벤토리 가득 찼는지 확인 함수
	bool IsFull(size_t maxSize) const
	{
		return items.size() >= maxSize;
	}

	//IsEmpty 인벤토리 비었는지 확인 함수
	bool IsEmpty() const
	{
		return items.empty();
	}

	//GetItemAt 인덱스에 있는 아이템 반환 함수
	void GetItemAt(size_t index, T& item) const
	{
		if (index < items.size())
		{
			item = items[index];
		}
		else
		{
			std::cerr << "Index out of bounds." << std::endl;
		}
	}

	//RemoveItemAt 인덱스에 있는 아이템 제거 함수
	void RemoveItemAt(size_t index)
	{
		if (index < items.size())
		{
			items.erase(items.begin() + index);
		}
		else
		{
			std::cerr << "Index out of bounds." << std::endl;
		}
	}


};