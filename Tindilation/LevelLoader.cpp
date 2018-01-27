#include "LevelLoader.h"

//gets string after the word job and after names
void operator >> (const YAML::Node& mirrorNode, MirrorData& mirror)
{
	mirror.length = mirrorNode["length"].as<int>();
	mirror.position.x = mirrorNode["position"]["x"].as<float>();
	mirror.position.y = mirrorNode["position"]["y"].as<float>();
}

//void operator >> (const YAML::Node& laserNode, )

//checks information after the word credits
void operator >> (const YAML::Node& levelNode, LevelData& level)
{
	const YAML::Node& mirrorNode = levelNode["mirrors"].as<YAML::Node>();
	for (unsigned i = 0; i < mirrorNode.size(); ++i)
	{
		MirrorData mirror;
		mirrorNode[i] >> mirror;
		level.m_mrrors.push_back(mirror);
	}
}

void operator >> (const YAML::Node& cableNode, CableData& cable)
{
	cable.position.x = cableNode["position"]["x"].as<float>();
	cable.position.y = cableNode["position"]["y"].as<float>();
}

bool LevelLoader::load(int t_levelNum, LevelData & t_screen)
{
	//checks yaml file
	std::stringstream ss;
	ss << "ASSETS/level";
	ss << t_levelNum;
	ss << ".yaml";

	try
	{
		YAML::Node baseNode = YAML::LoadFile(ss.str());
		if (baseNode.IsNull())
		{
			std::string message("file: " + ss.str() + " not found");
			throw std::exception(message.c_str());
		}
		baseNode >> t_screen;
	}
	catch (YAML::ParserException& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << "\n";
		return false;
	}

	return true;
}
