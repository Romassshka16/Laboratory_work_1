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


ostream& operator<<(ostream& out, const Pipe& p)
{
	out << "\tInformation about Pipe: " << "\"" << p.km_mark << "\"\n\n"
		<< "Kilometer mark: " << p.km_mark << "\n"
		<< "Length: " << p.length << " km" << "\n"
		<< "Diameter: " << p.diameter << " mm" << "\n"
		<< p.PrintStatus();

	return out;
}

std::ifstream& operator>>(ifstream& fin, Pipe& p)
{
	fin >> p.km_mark >> p.length >> p.diameter >> p.in_repair;
	return fin;
}

std::ofstream& operator<<(ofstream& fout, const Pipe& p)
{
	fout << p.km_mark << endl
		<< p.length << endl 
		<< p.diameter << endl
		<< p.in_repair << endl;
	return fout;
}


string Pipe::PrintStatus() const
{
	return in_repair ? "In repair" : "In Working condition";

}
