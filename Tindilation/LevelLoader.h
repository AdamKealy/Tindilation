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

struct LaserData
{
	sf::Vector2f position;
};

struct LevelData
{
	std::vector<MirrorData> m_mrrors;
	std::vector<LaserData> m_laser;
};

class LevelLoader
{
public:
	LevelLoader() = default;
	static bool load(int t_levelNum, LevelData& m_level);
};