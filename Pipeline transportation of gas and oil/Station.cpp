#include "Station.h"
#include "Addition.h"

using namespace std;

std::istream& operator>>(std::istream& in, Station& cs)
{
	cout << "Title: ";
	in >> ws;
	getline(in, cs.title);

	cout << "Number of all workshops (1 - 25): ";
	cs.all_workshop = GetCorrectNumber(1, 25);

	cout << "Number of active workshops (0 - " << cs.all_workshop <<"): ";
	cs.active_workshop = GetCorrectNumber(0, cs.all_workshop);

	cout << "Efficiency (0.0 - 1.0): ";
	cs.efficiency = GetCorrectNumber(0.0, 1.0);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Station& cs)
{
	out << "\tInformation about CS " << cs.id
		<< ": \"" << cs.title << "\"\n\n"
		<< "ID: " << cs.id << "\n"
		<< "Title: " << cs.title << "\n"
		<< "All workshops: " << cs.all_workshop << "\n"
		<< "Active workshops: " << cs.active_workshop << "\n"
		<< "Efficiency: " << cs.efficiency * 100 << " %" << "\n";

	return out;
}

std::ifstream& operator>>(std::ifstream& fin, Station& cs)
{
	fin >> cs.id;
	fin >> ws;
	getline(fin, cs.title);
	fin >> cs.all_workshop;
	fin >> cs.active_workshop;
	fin >> cs.efficiency;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, const Station& cs)
{
	fout << cs.id << "\n"
		<< cs.title << "\n"
		<< cs.all_workshop << "\n"
		<< cs.active_workshop << "\n"
		<< cs.efficiency << "\n";
	return fout;
}


int Station::max_id = 0;

int Station::GetId() const
{
	return id;
}

Station::Station()
{
	id = max_id++;
}
