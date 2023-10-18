#pragma once
#include <iostream>
#include <string>

class Station
{
public:
	int active_workshop;

	friend std::istream& operator >> (std::istream& in, Station& cs);
	friend std::ostream& operator << (std::ostream& out, Station& cs);

private:
	std::string title;
	int all_workshop;
	float efficiency;
};

