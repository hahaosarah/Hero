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
	T* pItems_;
	int size_;
	int capacity_;
	/*std::vector<T> items;*/

public:
	Inventory()
	:	pItems_(new T[10]),
		size_(0), 
		capacity_(10)
	{
	}
	~Inventory() 
	{
		delete[] pItems_;
	}


	//복사 생성자
	Inventory(const Inventory<T>& other)
	{
		pItems_ = new T[other.capacity_];
		capacity_ = other.capacity_;
		size_ = other.size_;
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}
		/*items = other.items;*/
	}

	//복사 대입 연산자
	Inventory<T>& operator=(const Inventory<T>& other)
	{
		if (this != &other)
		{
			delete[] pItems_;

			/*items = other.items;*/
			
			capacity_ = other.capacity_;
			size_ = other.size_;
			pItems_ = new T[capacity_];

			for (int i = 0; i < size_; ++i)
			{
				pItems_[i] = other.pItems_[i];
			}

		}
		return *this;
	}




	//AddItem 아이템	추가 함수
	void AddItem(const T& item) 
	{
		std::cout << " Adding item...(10/10 full)" << std::endl;
		/*items.push_back(item);*/
		if (size_ >= capacity_) 
		{
			Resize(capacity_ * 2); // 용량을 두 배로 늘림
			std::cout << " -> Inventory auto-expanded! (10 -> 20)" << std::endl;
		}

		pItems_[size_] = item;
		size_++;
		std::cout << " -> Item added" << std::endl;

	}

	//RemoveItem 아이템 제거 함수
	void RemoveItem(const T& item) 
	{
		for (int i = 0; i < size_; ++i) 
		{
			if (pItems_[i] == item) 
			{
				RemoveItemAt(i);
				return;
			}
		}
	}

	//ShowInventory 아이템 목록 출력 함수
	void ShowInventory() const
	{
		if ( size_ == 0 )
		{
			std::cout << "Inventory is empty." << std::endl;
			return;
		}

		std::cout << "Inventory:" << std::endl;

		int number = 1;

		for (int i = 0; i < size_; ++i)
		{
			std::cout << number << ". " << pItems_[i].name << " (" << pItems_[i].price << "G)" << std::endl;
			number++;
		}
	}

	//GetSize 아이템 개수 반환 함수
	size_t GetSize() const
	{
		return size_;
	}

	//IsFull 인벤토리 가득 찼는지 확인 함수
	bool IsFull() const
	{
		return size_ >= capacity_;
	}

	//IsEmpty 인벤토리 비었는지 확인 함수
	bool IsEmpty() const
	{
		return size_ == 0;
	}

	//GetItemAt 인덱스에 있는 아이템 반환 함수
	void GetItemAt(size_t index, T& item) const
	{
		if (index < size_ )
		{
			item = pItems_[index];
		}
		else
		{
			std::cerr << "Index out of bounds." << std::endl;
		}
	}

	//RemoveItemAt 인덱스에 있는 아이템 제거 함수
	void RemoveItemAt(size_t index)
	{
		if (index < size_ )
		{
			for (size_t i = index; i < size_ - 1; ++i)
			{
				pItems_[i] = pItems_[i + 1];
			}

			size_--;
		}
		else
		{
			std::cerr << "Index out of bounds." << std::endl;
		}
	}

	//RemoveLastItem 마지막 아이템 제거 함수
	void RemoveLastItem()
	{
		if (size_ > 0)
		{
			size_--;
		}
		else
		{
			std::cerr << "Inventory is empty." << std::endl;
		}
	}

	//PrintAllItems 모든 아이템 출력 함수
	void PrintAllItems() const
	{
		ShowInventory();
	}

	//GetCapacity 인벤토리 용량 반환 함수
	size_t GetCapacity() const
	{
		return capacity_;
	}

	//Resize 인벤토리 용량 조절 함수
	void Resize(int newCapacity)
	{
		if (newCapacity <= 0)
		{
			std::cerr << "New capacity must be greater than 0." << std::endl;
			return;
		}
		T* newItems = new T[newCapacity];
		for (int i = 0; i < size_ && i < newCapacity; ++i)
		{
			newItems[i] = pItems_[i];
		}
		delete[] pItems_;
		pItems_ = newItems;
		capacity_ = newCapacity;
		if (size_ > capacity_)
		{
			size_ = capacity_;
		}
	}

	//SortItems 아이템 가격 기준 정렬 함수
	void SortItems() 
	{
		std::sort(pItems_, pItems_ + size_, compareByPrice);
	}
	
};

