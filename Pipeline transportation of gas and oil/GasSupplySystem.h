#pragma once
#include <unordered_map>
#include <fstream>
#include <iostream>
#include "Pipe.h"
#include "Station.h"


class GasSupplySystem
{	
public:
	template <typename T> void Add(std::unordered_map<int, T>& map);
	template <typename T> void Show(std::unordered_map<int, T>& map);
	void Save();
	void Load();
	
	std::unordered_map<int, Pipe>& GetPipes();
	std::unordered_map<int, Station>& GetCS();


private:
	std::unordered_map<int, Pipe> pipe_map;
	std::unordered_map<int, Station> cs_map;

};

template<typename T>
inline void GasSupplySystem::Add(std::unordered_map<int, T>& map)
{
	T object;
	std::cin >> object;
	map.insert({ object.GetId(), object });
}

template<typename T>
inline void GasSupplySystem::Show(std::unordered_map<int, T>& map)
{
	for (const auto& [key, object] : map)
	{
		std::cout << object << std::endl;
	}
}

