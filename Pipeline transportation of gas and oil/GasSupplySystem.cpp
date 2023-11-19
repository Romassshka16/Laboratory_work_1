#include "GasSupplySystem.h"

using namespace std;

void GasSupplySystem::AddPipe()
{
	Pipe p;
	cin >> p;
	pipe_objects.insert({ p.GetId(), p });
}

void GasSupplySystem::AddCS()
{
	Station cs;
	cin >> cs;
	cs_objects.insert({ cs.GetId(), cs });
}

void GasSupplySystem::ShowPipes()
{
	if (ObjectsExist(pipe_objects)) {
		for (const auto& [id, pipe] : pipe_objects)
		{
			cout << pipe;
		}
	}
	else
		cout << "Not pipes!\n\n";
}

void GasSupplySystem::ShowCS()
{
	if (ObjectsExist(cs_objects)) {
		for (const auto& [id, station] : cs_objects)
		{
			cout << station;
		}
	}
	else
		cout << "Not staions!\n\n";
}

void GasSupplySystem::ShortShowPipes()
{
	for (const auto& [id, pipe] : pipe_objects) {
		cout << "ID " << id << ": \"" << pipe.GetKmMark()
			<< "\", " << pipe.PrintStatus() << "\n";
	}
	cout << "\n";
}

void GasSupplySystem::ShortShowCS()
{
	for (const auto& [id, station] : cs_objects) {
		cout << "ID " << id << ": \"" << station.GetTitle()
			<< "\", " << "Percent of unused workshops: "
			<< station.GetPercentUnused() << " %\n";
	}
	cout << "\n";
}

void GasSupplySystem::ShowFoundPipes(unordered_set<int>& id_pipes)
{
	for (const auto& id : id_pipes) {
		cout << "ID " << id << ": \"" << pipe_objects.at(id).GetKmMark()
			<< "\", " << pipe_objects.at(id).PrintStatus() << "\n";
	}
	cout << "\n";
}

void GasSupplySystem::ShowFoundCS(unordered_set<int>& id_cs)
{
	for (const auto& id : id_cs) {
		cout << "ID " << id << ": \"" << cs_objects.at(id).GetTitle()
			<< "\", " << "Percent of unused workshops: "
			<< cs_objects.at(id).GetPercentUnused() << " %\n";
	}
	cout << "\n";
}

void GasSupplySystem::Save(string filename)
{
	ofstream fout;
	fout.open("Data/" + filename);

	if (fout) {
		fout << pipe_objects.size() << " "
			<< cs_objects.size() << "\n";
		for (const auto& [key, pipe] : pipe_objects) {
			fout << pipe;
		}
		for (const auto& [key, cs] : cs_objects) {
			fout << cs;
		}
		cout << "Data is saved!" << "\n";
	}
	else 
		cout << "Error in the opening file!\n";

	fout.close();
}

void GasSupplySystem::Load(string filename)
{
	ifstream fin;
	fin.open("Data/" + filename);
	if (fin) {
		int num_pipe;
		int num_cs;
		Pipe p;
		Station cs;
		ClearSystem();

		fin >> num_pipe >> num_cs;		
		for (int i = 0; i < num_pipe; i++) {
			fin >> p;
			pipe_objects.insert({ p.GetId(), p });
		}

		for (int i = 0; i < num_cs; i++) {
			fin >> cs;
			cs_objects.insert({ cs.GetId(), cs });
		};
		cout << "Data is loaded!" << "\n";
	}
	else
		cout << "Error in the opening file!\n";
}

void GasSupplySystem::ClearSystem()
{
	Pipe::ResetMaxID();
	Station::ResetMaxID();
	pipe_objects.clear();
	cs_objects.clear();
}

bool CheckByKmMark(const Pipe& p, string param)
{
	return (p.GetKmMark().find(param) != string::npos);
}

bool ChekByStatus(const Pipe& p, int param)
{
	return (p.status == param);
}

bool CheckByTitle(const Station& cs, string param)
{
	return (cs.GetTitle().find(param) != string::npos);
}

bool CheckByWorkshops(const Station& cs, double param)
{
	return (cs.GetPercentUnused() >= param);
}

unordered_set<int> GasSupplySystem::SearchPipesByKmMark(string km_mark)
{
	return FindByFilter(pipe_objects, CheckByKmMark, km_mark);
}

unordered_set<int> GasSupplySystem::SearchPipesByStatus(int status)
{
	return FindByFilter(pipe_objects, ChekByStatus, status);
}

unordered_set<int> GasSupplySystem::SearchPipesByIDs()
{
	return SelectByIDs(pipe_objects);
}

void GasSupplySystem::EditOnePipe(int id_pipe)
{
	if (pipe_objects.contains(id_pipe)) {
		pipe_objects.at(id_pipe).ChangeStatus();
		cout << "Status is changed!\n";
	}
	else
		cout << "Pipe with entered ID not found!\n";
}

void GasSupplySystem::ChangeStatusToOpposite(unordered_set<int>& id_pipes)
{
	if (ObjectsExist(id_pipes))
	{
		for (auto& id : id_pipes)
			pipe_objects.at(id).ChangeStatus();
		cout << "Statuses of pipes are changed!\n";
	}
	else
		cout << "Pipes are not found!\n";
}

void GasSupplySystem::ChangeStatusToRepair(unordered_set<int>& id_pipes)
{
	if (ObjectsExist(id_pipes))
	{
		for (auto& id : id_pipes)
			if (!pipe_objects.at(id).status)
				pipe_objects.at(id).ChangeStatus();
		cout << "Statuses of pipes are changed!\n";
	}
	else
		cout << "Pipes are not found!\n";
}

void GasSupplySystem::ChangeStatusToWork(unordered_set<int>& id_pipes)
{
	if (ObjectsExist(id_pipes))
	{
		for (auto& id : id_pipes)
			if (pipe_objects.at(id).status)
				pipe_objects.at(id).ChangeStatus();
		cout << "Statuses of pipes are changed!\n";
	}
	else
		cout << "Pipes are not found!\n";
}

void GasSupplySystem::EditAllPipes()
{
	for (auto& [id, pipe] : pipe_objects)
		pipe.ChangeStatus();
}

unordered_set<int> GasSupplySystem::SearchCSByTitle(std::string title)
{
	return FindByFilter(cs_objects, CheckByTitle, title);
}

unordered_set<int> GasSupplySystem::SearchCSByWorkshops(double percent)
{
	return FindByFilter(cs_objects, CheckByWorkshops, percent);
}

unordered_set<int> GasSupplySystem::SearchCSByIDs()
{
	return SelectByIDs(cs_objects);
}

void GasSupplySystem::EditOneCS(int id_cs)
{
	if (cs_objects.contains(id_cs)) {
		cout << "\"1\" - Increase,\"0\" - Decrease: ";
		GetCorrectNumber(0, 1) ? cs_objects.at(id_cs).IncreaseActiveWS() :
			cs_objects.at(id_cs).DecreaseActiveWS();
		cout << "Number of WS is changed\n";
	}
	else
		cout << "Station with entered ID not found!\n";
}

void GasSupplySystem::EditCSPackage(
	std::unordered_set<int>& id_cs, int action)
{
	for (auto& id : id_cs) {
		action ? cs_objects.at(id).IncreaseActiveWS() :
			cs_objects.at(id).DecreaseActiveWS();
	}

}

void GasSupplySystem::EditAllCS(int action)
{
	for (auto& [id, cs] : cs_objects)
		action ? cs.IncreaseActiveWS():cs.DecreaseActiveWS();
}

void GasSupplySystem::DeletePipe(int id_pipe)
{
	if (pipe_objects.contains(id_pipe)) {
		pipe_objects.erase(id_pipe);
		cout << "Pipe was deleted\n";
	}
	else
		cout << "Pipe with entered ID not found!\n";
}

void GasSupplySystem::DeleteCS(int id_cs)
{
	if (cs_objects.contains(id_cs)) {
		cs_objects.erase(id_cs);
		cout << "Station was deleted\n";
	}
	else
		cout << "Station with entered ID not found!\n";
}

bool GasSupplySystem::IsPipeObjectsEmpty()
{
	if (pipe_objects.size() == 0)
		return true;
	return false;
}

bool GasSupplySystem::IsCSObjectsEmpty()
{
	if (cs_objects.size() == 0)
		return true;
	return false;
}
