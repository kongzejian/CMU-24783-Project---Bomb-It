#pragma once
//2D point coordinate
struct Point2D{
	int x, y;
};

struct Cell{
	int x, y;

	bool operator!=(const Cell& other) const {
        return (x != other.x) || (y != other.y);
    }
};

//four directions
enum class Orientation{
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

enum class HandSkill{
	BOMB,
	MINE
};


enum class MapItem{
	FLOOR,
	GREEN_TREE,
	RED_HOUSE,
	WALL,
	BLUE_ROADBLOCK,
	RED_ROADBLOCK,
	STREET_LAMP,

	PLAYER1,
	PLAYER2,
	PLAYER3,
	PLAYER4,
	DEADBODY,
	BOMB,
	EXPCENTER,
	EXPMIDDLEH,
	EXPMIDDLEV,
	EXPENDL,
	EXPENDR,
	EXPENDU,
	EXPENDD,
	ICE,
	HEALTHCARE,
	SNEAKER,
	RANGE,
	BOMBADD,
	MINETOPICKUP,
	MINEPLACE
};
