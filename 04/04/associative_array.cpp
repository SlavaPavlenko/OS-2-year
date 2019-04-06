#include "pch.h"
#include "associative_array.h"
#include <string>
#include <iostream>
#include <functional>
#include <list>
#include <vector>

associative_array::associative_array()
{
	arr = new std::vector<Pare>;	
}

void associative_array::add(std::string str, int value)
{
	std::hash<std::string> hash;
	int str_hash = hash(str);
	unsigned int i = 0;
	Pare pare;
	while (i < arr->size() && pare.key != str_hash)
	{
		pare = arr->at(i);
		i++;
	}
	if (pare.key == str_hash)
	{
		arr->at(i - 1).list.push_back(value);
	}
	else
	{
		arr->push_back(Pare{ str_hash, std::list<int>() });
		arr->at(i).list.push_back(value);
	}
}

void associative_array::del(std::string str, int value)
{
	std::hash<std::string> hash;
	int str_hash = hash(str);
	Pare pare;
	bool end = false;
	unsigned int i = 0;
	while (i < arr->size() && !end)
	{
		if (str_hash == arr->at(i).key)
		{
			arr->at(i).list.remove(value);
			end = true;
		}
		i++;
	}
}

void associative_array::find(std::string str)
{
	std::hash<std::string> hash;
	int str_hash = hash(str);
	unsigned int i = 0;
	bool end = false;
	std::cout << "Результат поиска по запросу " << str << ": ";
	while (i < arr->size() && !end)
	{
		if (str_hash == arr->at(i).key)
		{
			auto iterator = arr->at(i).list.begin();
			unsigned int j = 0;
			while (iterator != arr->at(i).list.end())
			{
				std::cout << "\n   " << *iterator;
				iterator++;
			}
			end = true;
			std::cout << "\n";
		}
		i++;
	}
	if (!end)
		std::cout << "не найдено\n\n";
}

void associative_array::print()
{
	unsigned int i = 0;
	Pare pare;
	while (i < arr->size())
	{
		pare = arr->at(i);
		if (!(pare.list.empty()))
		{
			std::cout << "Ключ: " << arr->at(i).key << "\nСписок:\n";
			auto iterator = pare.list.begin();
			while (iterator != pare.list.end())
			{
				std::cout << "   " << *iterator << "\n";
				iterator++;
			}
			std::cout << "\n";
		}
		i++;
	}
}

associative_array::~associative_array()
{
}
