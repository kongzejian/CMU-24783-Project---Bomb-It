#pragma once
#include "definitions.h"
#include "yspng.h"
#include "fssimplewindow.h"
#include "bitmap.h"
#include "map.h"
#include <algorithm>
#include <map>
class PowerUp{
protected:
    Cell loc;
public:
    friend class Character;
    PowerUp() {}
	PowerUp(Cell location) {
		loc = location;
	}
    bool checkPlayerPickUp(std::map<MapItem, Character>& playerList);
    void pickedUp(struct GameMapUnit (&gameMap)[15][17]);
    virtual void effect(Character &player);
    virtual void initialized(struct GameMapUnit (&gameMap)[15][17]);
};

class HealthCare: public PowerUp{
public:
    HealthCare(Cell location) {
		loc = location;
	}
    void effect(Character &player);
    void initialized(struct GameMapUnit (&gameMap)[15][17]);
};

class Range: public PowerUp{
public:
    Range(Cell location) {
		loc = location;
	}
    void effect(Character &player);
    void initialized(struct GameMapUnit (&gameMap)[15][17]);
};

class Sneaker: public PowerUp{
public:
    Sneaker(Cell location) {
		loc = location;
	}
    void effect(Character &player);
    void initialized(struct GameMapUnit (&gameMap)[15][17]);
}; 

class BombAdd: public PowerUp{
public:
    BombAdd(Cell location) {
		loc = location;
	}
    void effect(Character &player);
    void initialized(struct GameMapUnit (&gameMap)[15][17]);
};


class Mine: public PowerUp{
public:
     Mine(Cell location) {
		loc = location;
	}
    void effect(Character &player);
    void initialized(struct GameMapUnit (&gameMap)[15][17]);
    
}; 