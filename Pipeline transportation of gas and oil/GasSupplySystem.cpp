#include "GasSupplySystem.h"

using namespace std;


void GasSupplySystem::Save()
{
	string filename;
	cout << "Enter the file name: ";
	cin >> ws;
	getline(cin, filename);

	ofstream fout;
	fout.open(filename);

	if (fout) {
		fout << pipe_map.size() << " " << cs_map.size() << "\n";
		for (const auto& [key, pipe] : pipe_map) {
			fout << pipe;
		}
		for (const auto& [key, cs] : cs_map) {
			fout << cs;
		}
	}
	else {
		cout << "Error in the opening file" << "\n";
	}

	fout.close();
}


void GasSupplySystem::Load()
{
	string filename;
	cout << "Enter the file name: ";
	cin >> ws;
	getline(cin, filename);

	ifstream fin;
	fin.open(filename);
	if (fin) {
		int num_pipe;
		int num_cs;
		int temp_id_p = 0;
		int temp_id_cs = 0;
		Pipe p;
		Station cs;

		fin >> num_pipe >> num_cs;		
		for (int i = 0; i < num_pipe; i++) {
			fin >> p;
			pipe_map.insert({ p.GetId(), p });
			if (p.GetId() > temp_id_p)
				temp_id_p = p.GetId();
		}

		for (int i = 0; i < num_cs; i++) {
			fin >> cs;
			cs_map.insert({ cs.GetId(), cs });
			if (cs.GetId() > temp_id_cs)
				temp_id_cs = cs.GetId();
		}
		Pipe::max_id = temp_id_p + 1;
		Station::max_id = temp_id_cs + 1;
	}
	else
	{
		cout << "Error in the opening file" << "\n";
	}
}


std::unordered_map<int, Pipe>& GasSupplySystem::GetPipes()
{
	return pipe_map;
}


std::unordered_map<int, Station>& GasSupplySystem::GetCS()
{
	return cs_map;
}
