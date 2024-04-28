#pragma once
class PowerUp;
#include <iostream>
#include "definitions.h"
#include "yspng.h"
#include "fssimplewindow.h"
#include "bitmap.h"
#include "character.h"
#include "bomb.h"
#include "powerUp.h"
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <cstdio>
#include <random>
#include "weapon.h"
#include "yssimplesound.h"
#include "ysglfontdata.h"

struct GameMapUnit{
	MapItem backGround;
	std::vector<MapItem> playerHere;
	std::vector<MapItem> bombHere;
	std::vector<MapItem> explodeHere;
	std::vector<MapItem> powerUpHere;
	std::vector<MapItem> weaponHere;
};

class Map{
public:
	friend class Character;
	friend class Game;
	friend class PowerOn;
	friend class weapon;
	friend class Bomb;

	static const int MAP_WIDTH = 17;
	static const int MAP_HEIGHT = 15;
	double scale = 0.2;
	YsSoundPlayer explosionSoundPlayer;
	YsSoundPlayer::SoundData explosionSound;
	RGBABitmap gameOver;
private:
	mutable GameMapUnit GameMap[MAP_HEIGHT][MAP_WIDTH];
	mutable std::map<MapItem, RGBABitmap> textures;
	mutable RGBABitmap statusBarImg;
	mutable std::map<MapItem, Character> playerList;
	mutable std::vector<class Bomb> bombList;
	mutable std::vector<PowerUp*> powerUpList;
	mutable std::vector<weapon*> weaponList;
	mutable std::map<MapItem, std::vector<std::vector<bool>>> visitedMap;
	mutable std::map<MapItem, std::vector<Orientation>> priorityDir;

public:
	Map(){
		if(YSOK == explosionSound.LoadWav("../Bomb it/soundEffect/explosion.wav")) 
		{
		std::cout << "success to read "  << std::endl;
		explosionSoundPlayer.Start();
		}
		else
		{
		std::cout << "Failed to read "  << std::endl;
		}
		createMap();
	}
	void createMap();
	void draw();
	void loadPNG(std::vector<const char*> imgPaths);
	void addPlayer(MapItem playerID, char* frontImg, const char* backImg, const char* leftImg, const char* rightImg, Point2D location);
	void movePlayer(MapItem playerID, Orientation orientation);
	void placeBomb(MapItem playerID);
	void placeMine(MapItem playerID);
	void checkBomb();
	void placePowerUp(MapItem powerUpItem, Cell loc); //add a controller to generate powerup item
	void checkPowerUp();
	int checkBombNumberForOnePlayer(MapItem playerID);
	int getPlayerBombUpLimit(MapItem playerID);
	void placeWeapon(MapItem playerID);
	void checkWeaponTimeToinvisibility();
	void checkWeapon();
	void drawSB();
	void autoDecision(MapItem playerID);
	bool isValidMove(const std::vector<std::vector<bool>>& visited, int row, int col);
	bool hasPlayerInRange(MapItem playerID);
	Cell hasBombInRange(MapItem playerID);
	bool checkgameOver();
};