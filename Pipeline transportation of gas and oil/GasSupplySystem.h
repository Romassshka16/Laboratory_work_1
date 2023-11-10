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

	template <typename T> 
	void Show(const std::unordered_map<int, T>& objects);
	void ShowObjects();

	void Save();
	void Load();
	void ClearSystem();
	void EditPipe();
	void EditCS();
	
	
	std::unordered_map<int, Pipe>& GetPipes();
	std::unordered_map<int, Station>& GetCS();

private:
	std::unordered_map<int, Pipe> pipe_objects;
	std::unordered_map<int, Station> cs_objects;

};


template<typename T>
inline void GasSupplySystem::Show(const std::unordered_map<int, T>& objects)
{
	if (objects.size() != 0) {
		for (const auto& [key, object] : objects)
		{
			std::cout << object;
		}
	}
	else
		std::cout << "Not objects!\n\n";
}


