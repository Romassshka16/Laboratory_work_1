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
	out << "\tInformation about Pipe " << p.id <<
		": \"" << p.km_mark << "\"\n\n"
		<< "ID: " << p.id << "\n"
		<< "Kilometer mark: " << p.km_mark << "\n"
		<< "Length: " << p.length << " km" << "\n"
		<< "Diameter: " << p.diameter << " mm" << "\n"
		<< p.PrintStatus() << "\n";

	return out;
}

std::ifstream& operator>>(ifstream& fin, Pipe& p)
{
	fin >> p.id;
	fin >> ws;
	getline(fin, p.km_mark);
	fin >> p.length;
	fin >> p.diameter;
	fin >> p.in_repair;
	return fin;
}

std::ofstream& operator<<(ofstream& fout, const Pipe& p)
{
	fout << p.id << "\n"
		<< p.km_mark << "\n"
		<< p.length << "\n" 
		<< p.diameter << "\n"
		<< p.in_repair << "\n";
	return fout;
}


string Pipe::PrintStatus() const
{
	return in_repair ? "In repair" : "In Working condition";

}

int Pipe::GetId() const
{
	return id;
}


int Pipe::max_id = 0;


Pipe::Pipe()
{
	id = max_id++;
}
