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

std::ostream& operator<<(std::ostream& out, Station& cs)
{
	out << "\tInformation about CS: " << "\"" << cs.title << "\"\n\n"
		<< "Title: " << cs.title << "\n"
		<< "All workshops: " << cs.all_workshop << "\n"
		<< "Active workshops: " << cs.active_workshop << "\n"
		<< "Efficiency: " << cs.efficiency * 100 << " %" << "\n";

	return out;
}

std::ifstream& operator>>(std::ifstream& fin, Station& cs)
{
	fin >> cs.title >> cs.all_workshop >> cs.active_workshop >> cs.efficiency;
	return fin;
}

std::ofstream& operator<<(std::ofstream& fout, Station& cs)
{
	fout << cs.title << endl
		<< cs.all_workshop << endl
		<< cs.active_workshop << endl
		<< cs.efficiency << endl;
	return fout;
}
