#pragma once
#include "definitions.h"
#include "yspng.h"
#include "fssimplewindow.h"
#include "bitmap.h"
#include "map.h"
#include <string>
#include <ctime>
#include <vector>
#include <random>

class Bomb{
private:
    clock_t placeTime;
	Cell loc;
	int explodeRange;
	MapItem playerID;
	
public:
	Bomb() {}
	Bomb(int range, Cell location,MapItem id) {
		placeTime = clock();
		loc = location;
		explodeRange = range;
		playerID = id;
	}
	clock_t getPlaceTime();
	void countDown(struct GameMapUnit (&gameMap)[15][17]);
	void explode(struct GameMapUnit (&gameMap)[15][17], class Map &map);
	bool canDestroy(MapItem item);
	MapItem belongTo(){return playerID;}
};