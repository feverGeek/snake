#include "Map.h"
#include <Windows.h>

void Map::printmap()
{
	for (auto& Point : vec_map)
	{
		Point.printRect();
		Sleep(10);
	}
}
