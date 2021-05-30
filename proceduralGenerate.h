#pragma once

#include <random>
#include <iostream>

// 0 - W to E
// 1 - N to E
// 2 - NWSE
// 3 - N to S
// 4 - N to W
// 5 - No Road
// 6 - S to E
// 7 - S to W
// 8 - N, S, E
// 9 - N, W, E
// 10 - S, W, E
// 11 - N, S, W

#define MAP_SIZE 100

enum {
	ROAD_EAST_WEST = 0,
	ROAD_CORNER_NORTH_TO_EAST = 1,
	READ_CROSS = 2,
	ROAD_NORTH_SOUTH = 3,
	ROAD_CORNER_NORTH_TO_WEST = 4,
	NO_ROAD = 5,
	ROAD_CORNER_SOUTH_TO_EAST = 6,
	ROAD_CORNER_SOUTH_TO_WEST = 7,
	ROAD_TEE_EAST = 8,
	ROAD_TEE_SOUTH = 9,
	ROAD_TEE_NORTH = 10,
	ROAD_TEE_WEST = 11,
};

int gmap[MAP_SIZE][MAP_SIZE];

void generateMap()
{
	bool noParRoad = true;
	gmap[0][0] = ROAD_CORNER_SOUTH_TO_EAST;
	gmap[MAP_SIZE - 1][0] = ROAD_CORNER_SOUTH_TO_WEST;
	gmap[0][MAP_SIZE - 1] = ROAD_CORNER_NORTH_TO_EAST;
	gmap[MAP_SIZE - 1][MAP_SIZE - 1] = ROAD_CORNER_NORTH_TO_WEST;
	for (int mx = 1; mx < MAP_SIZE - 1; mx++) // Horizontal Borders
	{
		if (rand() % 3 == 2 && noParRoad == false)
		{
			gmap[mx][0] = ROAD_TEE_NORTH;
			gmap[mx][MAP_SIZE - 1] = ROAD_TEE_SOUTH;
			noParRoad = true;
		}
		else
		{
			gmap[mx][0] = ROAD_EAST_WEST;
			gmap[mx][MAP_SIZE - 1] = ROAD_EAST_WEST;
			noParRoad = false;
		}
	}
	for (int my = 1; my < MAP_SIZE - 1; my++) // Vertical Borders
	{
		if (rand() % 3 == 2 && noParRoad == false)
		{
			gmap[0][my] = ROAD_TEE_EAST;
			gmap[MAP_SIZE - 1][my] = ROAD_TEE_WEST;
			noParRoad = true;
		}
		else
		{
			gmap[0][my] = ROAD_NORTH_SOUTH;
			gmap[MAP_SIZE - 1][my] = ROAD_NORTH_SOUTH;
			noParRoad = false;
		}
	}
	for (int mx = 1; mx < MAP_SIZE - 1; mx++)
	{
		for (int my = 1; my < MAP_SIZE - 1; my++)
		{
			if (gmap[mx][0] == ROAD_TEE_NORTH && gmap[0][my] == ROAD_TEE_EAST)
			{
				gmap[mx][my] = READ_CROSS;
			}
			else if (gmap[mx][0] == ROAD_TEE_NORTH)
			{
				gmap[mx][my] = ROAD_NORTH_SOUTH;
			}
			else if (gmap[0][my] == ROAD_TEE_EAST)
			{
				gmap[mx][my] = ROAD_EAST_WEST;
			}
			else
			{
				gmap[mx][my] = (rand() % 17) + 100;
			}
		}
	}
}


