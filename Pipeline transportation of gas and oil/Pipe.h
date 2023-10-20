#pragma once
#include <iostream>
#include <fstream>
#include <string>


class Pipe
{
public:
	static int max_id;
	bool in_repair;

	friend std::istream& operator >> (std::istream& in, Pipe& p);
	friend std::ostream& operator << (std::ostream& out, const Pipe& p);
	friend std::ifstream& operator >> (std::ifstream& fin, Pipe& p);
	friend std::ofstream& operator << (std::ofstream& fout, const Pipe& p);
	std::string PrintStatus() const;
	int GetId() const;

	Pipe();

private:
	std::string km_mark;
	float length;
	int diameter;
	int id;

};

