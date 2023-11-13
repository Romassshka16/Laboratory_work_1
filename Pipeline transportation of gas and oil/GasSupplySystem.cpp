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

void GasSupplySystem::ShowCSs()
{
	if (cs_objects.size() != 0) {
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
	cout << "\n~ALL STATIONS~\n\n";
	if (ObjectsExist(cs_objects)) {
		for (const auto& [id, station] : cs_objects) {
			cout << "ID " << id << ": \"" << station.GetTitle()
				<< "\", " << "Percent of unused workshops: "
				<< station.GetPercentUnused() << " %\n";
		}
		cout << "\n";
	}
	else
		cout << "Not stations!\n\n";
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
	cout << "\n~FOUND STATIONS~\n\n";
	if (ObjectsExist(id_cs)) {
		for (const auto& id : id_cs) {
			cout << "ID " << id << ": \"" << cs_objects.at(id).GetTitle()
				<< "\", " << "Percent of unused workshops: "
				<< cs_objects.at(id).GetPercentUnused() << " %\n";
		}
		cout << "\n";
	}
	else
		cout << "Stations are not found!\n\n";
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
		cout << "Data is load!" << "\n";
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

bool CheckByWorkshop(const Station& cs, double param)
{
	return (cs.GetPercentUnused() >= param);
}

unordered_set<int> GasSupplySystem::SearchPipesByKmMark(string km_mark)
{
	return FindByFilter(pipe_objects, CheckByKmMark, km_mark);;
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

void GasSupplySystem::EditOneCS(int id_cs, int action)
{
	if (cs_objects.contains(id_cs)) {
		action ? cs_objects.at(id_cs).IncreaseActiveWS() :
			cs_objects.at(id_cs).DecreaseActiveWS();
		cout << "Number of WS is " << (action ? "increased" : "decreased") << "\n";
	}
	else
		cout << "Station with entered ID not found!\n";
}

void GasSupplySystem::EditCSPackage()
{
}

void GasSupplySystem::EditAllCSs()
{
}

bool GasSupplySystem::PipeExist(int id_pipe)
{
	if (pipe_objects.contains(id_pipe))
		return true;
	return false;
}

bool GasSupplySystem::StationExist(int id_cs)
{
	if (cs_objects.contains(id_cs))
		return true;
	return false;
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




//
//void DeletePipe(unordered_map<int, Pipe>& pipe_objects) {
//	ShortShowPipes(pipe_objects);
//	cout << "\nEnter ID of pipe: ";
//	int id = GetCorrectNumber(0, INT_MAX);
//	if (pipe_objects.count(id) != 0) {
//		pipe_objects.erase(id);
//		cout << "Pipe was deleted!\n";
//	}
//	else
//		cout << "Pipe with this ID has not found\n";
//}
//

//void ShowFoundStations(unordered_map<int, Station>& cs_objects,
//	unordered_set<int>& id_set) {
//	cout << "\n\t~FOUND STATIONS~\n\n";
//	for (auto& id : id_set) {
//		cout << "ID " << id << ": \""
//			<< cs_objects.at(id).GetTitle() << "\", "
//			<< "Percent of unused workshops: "
//			<< cs_objects.at(id).GetPercentUnused() << "% \n";
//	}
//	cout << "\n";
//}
//
//void EditOneStation(unordered_map<int, Station>& cs_objects) {
//	ShortShowStations(cs_objects);
//	cout << "\nEnter ID of station: ";
//	int id = GetCorrectNumber(0, INT_MAX);
//	if (cs_objects.count(id) != 0) {
//		cout << "\"0\" - Decrease,\"1\" - Increase: ";
//		GetCorrectNumber(0, 1) ? cs_objects.at(id).IncreaseActiveWS() :
//			cs_objects.at(id).DecreaseActiveWS();
//		cout << "The number of active workshops is changed\n";
//	}
//	else
//		cout << "Station with this ID has not found!\n";
//}
//
//void EditStations(unordered_map<int, Station>& cs_objects,
//	unordered_set<int>& id_set)
//{
//	ShowFoundStations(cs_objects, id_set);
//	vector<string> menu = { "Increase by 1 active workshop",
//	"Decrease by 1 active workshop" };
//	switch (ChooseActionMenu(menu, true))
//	{
//	case 1:
//	{
//		for (auto& id : id_set) {
//			cs_objects.at(id).IncreaseActiveWS();
//		}
//		cout << "The number of active workshops is changed\n";
//		break;
//	}
//	case 2:
//	{
//		for (auto& id : id_set) {
//			cs_objects.at(id).DecreaseActiveWS();
//		}
//		cout << "The number of active workshops is changed\n";
//		break;
//	}
//	case 0:
//	{
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void EditAllStations(unordered_map<int, Station>& cs_objects)
//{
//	unordered_set<int> id_set;
//	for (auto& [id, stations] : cs_objects) {
//		id_set.insert(id);
//	}
//	if (ObjectsExist(id_set))
//		EditStations(cs_objects, id_set);
//}
//
//void EditPackageStation(unordered_map<int, Station>& cs_objects)
//{
//	vector<string> menu = { "Search by title",
//	"Search by percent unused workshops",
//	"Select stations", "Edit all stations" };
//	switch (ChooseActionMenu(menu, true))
//	{
//	case 1:
//	{
//		ShortShowStations(cs_objects);
//		cout << "\nEnter the title: ";
//		unordered_set id_set = FindByFilter(cs_objects, CheckByTitle, EnterLine());
//		if (ObjectsExist(id_set))
//			EditStations(cs_objects, id_set);
//		break;
//	}
//	case 2:
//	{
//		ShortShowStations(cs_objects);
//		cout << "\nPercent of unused workshops: ";
//		unordered_set id_set = FindByFilter(cs_objects, CheckByWorkshop, GetCorrectNumber(0.0, 100.0));
//		if (ObjectsExist(id_set))
//			EditStations(cs_objects, id_set);
//		break;
//	}
//	case 3:
//	{
//		ShortShowStations(cs_objects);
//		unordered_set<int> id_set = SelectByIDs(cs_objects);
//		if (ObjectsExist(id_set))
//			EditStations(cs_objects, id_set);
//		break;
//	}
//	case 4:
//	{
//		EditAllStations(cs_objects);
//		break;
//	}
//	case 0:
//	{
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void DeleteStation(unordered_map<int, Station>& cs_objects) {
//	ShortShowStations(cs_objects);
//	cout << "\nEnter ID of station: ";
//	int id = GetCorrectNumber(0, INT_MAX);
//	if (cs_objects.count(id) != 0) {
//		cs_objects.erase(id);
//		cout << "Statoin was deleted!\n";
//	}
//	else
//		cout << "Station with this ID has not found\n";
//}

//void GasSupplySystem::EditCS()
//{
//	if (ObjectsExist(cs_objects))
//	{
//		vector<string>menu = { "Edit one station",
//		"Edit station package" };
//		switch (ChooseActionMenu(menu, true))
//		{
//		case 1:
//		{
//			EditOneStation(cs_objects);
//			break;
//		}
//		case 2:
//		{
//			EditPackageStation(cs_objects);
//			break;
//		}
//		case 3:
//		{
//			DeleteStation(cs_objects);
//			break;
//		}
//		case 0:
//		{
//
//			break;
//		}
//		default:
//			break;
//		}
//	}
//}


