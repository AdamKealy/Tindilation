#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include "yaml-cpp\yaml.h"

struct MirrorData
{
	int length;
	sf::Vector2f position;
};

struct CableData
{
	sf::Vector2f position;
	sf::Vector2f length;
	int rotation;
};

//struct LaserData
//{
//	sf::Vector2f position;
//};

struct LevelData
{
	std::vector<MirrorData> m_mrrors;
	std::vector<CableData> m_cable;/*
	std::vector<LaserData> m_laser;*/
};

class LevelLoader
{
public:
	LevelLoader() = default;
	static bool load(int t_levelNum, LevelData& m_level);
};