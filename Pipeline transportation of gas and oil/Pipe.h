#pragma once
#include <iostream>
#include <string>


class Pipe
{
public:
	bool in_repair;

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, Pipe& p);
	std::string PrintStatus() const;

private:
	std::string km_mark;
	float length;
	int diameter;

};

