#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Station
{
public:
	int active_workshop;
	static int max_id;

	friend std::istream& operator >> (std::istream& in, Station& cs);
	friend std::ostream& operator << (std::ostream& out, const Station& cs);
	friend std::ifstream& operator >> (std::ifstream& fin, Station& cs);
	friend std::ofstream& operator << (std::ofstream& fout, const Station& cs);

	int GetId() const;

	Station();

private:
	std::string title;
	int all_workshop;
	float efficiency;
	int id;
};

