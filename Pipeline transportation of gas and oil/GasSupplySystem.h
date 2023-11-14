#pragma once
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <vector>
#include "Pipe.h"
#include "Station.h"
#include "Addition.h"


class GasSupplySystem
{	
public:
	void AddPipe();
	void AddCS();

	void ShowPipes();
	void ShowCS();
	void ShortShowPipes();
	void ShortShowCS();
	void ShowFoundPipes(std::unordered_set<int>& id_pipes);
	void ShowFoundCS(std::unordered_set<int>& id_cs);

	void Save(std::string filename);
	void Load(std::string filename);
	void ClearSystem();

	std::unordered_set<int> SearchPipesByKmMark(std::string km_mark);
	std::unordered_set<int> SearchPipesByStatus(int status);
	std::unordered_set<int> SearchPipesByIDs();

	void EditOnePipe(int id_pipe);
	void ChangeStatusToOpposite(std::unordered_set<int>& id_pipes);
	void ChangeStatusToRepair(std::unordered_set<int>& id_pipes);
	void ChangeStatusToWork(std::unordered_set<int>& id_pipes);
	void EditAllPipes();

	std::unordered_set<int> SearchCSByTitle(std::string title);
	std::unordered_set<int> SearchCSByWorkshops(double percent);
	std::unordered_set<int> SearchCSByIDs();

	void EditOneCS(int id_cs);
	void EditCSPackage(std::unordered_set<int>& id_cs, int action);
	void EditAllCS(int action);

	void DeletePipe(int id_pipe);
	void DeleteCS(int id_cs);

	bool IsPipeObjectsEmpty();
	bool IsCSObjectsEmpty();

private:
	std::unordered_map<int, Pipe> pipe_objects;
	std::unordered_map<int, Station> cs_objects;
};

