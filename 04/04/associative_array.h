#pragma once
#include <string>
#include <list>
#include <vector>
class associative_array
{
	struct Pare {
		int key;
		std::list<int> list;
	};
	std::vector<Pare> * arr;
public:
	associative_array();
	void add(std::string, int);
	void del(std::string, int);
	void find(std::string);
	void print();
	~associative_array();
};

