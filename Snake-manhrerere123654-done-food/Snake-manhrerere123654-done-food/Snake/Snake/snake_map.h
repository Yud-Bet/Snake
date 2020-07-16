#pragma once
#include <string>
#include "Snake.h"

class snake_map
{
private:
	int w;
	int h;
	char** s_map;
public:
	snake_map(const std::string&);
	snake_map(int, int);
	bool is_map_being_eaten(coord);
	void print_map();
};

