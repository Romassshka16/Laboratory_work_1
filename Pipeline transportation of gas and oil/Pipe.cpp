#include "Pipe.h"
#include "Addition.h"


using namespace std;


istream& operator>>(istream& in, Pipe& p)
{
	cout << "Kilometer mark: ";
	in >> ws;
	getline(in, p.km_mark);
	
	cout << "Length (1 - 5000 km): ";
	p.length = GetCorrectNumber(1.0, 5000.0);
	
	cout << "Diameter (700 - 1400 mm): ";
	p.diameter = GetCorrectNumber(700, 1400);
	
	cout << "Is this pipe in repair? (y/n): ";
	p.in_repair = (GetCorrectChar() == 'y') ? true : false;

	return in;
}


ostream& operator<<(ostream& out, Pipe& p)
{
	out << "\tInformation about pipe: " << "\"" << p.km_mark << "\"\n\n";
	out << "Kilometer mark: " << p.km_mark << "\n";
	out << "Length: " << p.length << " km" << "\n";
	out << "Diameter: " << p.diameter << " mm" << "\n";
	out << p.PrintStatus();

	return out;
}


string Pipe::PrintStatus() const
{
	return in_repair ? "In repair" : "In Working condition";

}
