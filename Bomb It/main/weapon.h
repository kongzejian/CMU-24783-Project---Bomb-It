#pragma once
#include "definitions.h"
#include "yspng.h"
#include "fssimplewindow.h"
#include "bitmap.h"
#include "map.h"

#include <string>
#include <ctime>
#include <vector>

class weapon{
protected:
    clock_t placeTime;
	Cell loc;
	MapItem playerID;
public:
	clock_t getPlaceTime();
	MapItem belongTo(){return playerID;}
	virtual void countDown(struct GameMapUnit (&gameMap)[15][17]);
	virtual void shrink(clock_t __cdecl currentTime,GameMapUnit (&gameMap)[15][17]);
	virtual void effect(Character &player);
	bool checkStepOn(std::map<MapItem, Character>& playerList, GameMapUnit (&gameMap)[15][17]);
};



class realMine :public weapon{

public:
	realMine() {}
	realMine(Cell location,MapItem id) {
		placeTime = clock();
		loc = location;
		playerID = id;
	}
	void explode(struct GameMapUnit (&gameMap)[15][17]);
	void countDown(struct GameMapUnit (&gameMap)[15][17]);
	void shrink(clock_t __cdecl currentTime,GameMapUnit (&gameMap)[15][17]);
	void effect(Character &player);
};