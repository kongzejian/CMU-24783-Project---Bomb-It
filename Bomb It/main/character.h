#pragma once
#include "yspng.h"
#include "fssimplewindow.h"
#include "definitions.h"
#include "bitmap.h"
#include "map.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <ctime>

class Character{
	private:
		Point2D loc;
		int speed = 5;
		MapItem ID;
		bool canMove = true;
		Orientation orientation;
		int explodeRange;
		std::vector<RGBABitmap> orientationImg;
		RGBABitmap deadBodyImg;
		bool survive = 1;
		int blood = 3;
		bool invincible = 0;
		clock_t invincibleTime;
		clock_t deadTime;
		int bombNumber = 1;
		std::vector<HandSkill> handskill; //when place space key, what kind of weapon should be placed? bomb ? ice ? mine?
	public:
		friend class Map;
		Character(){
			orientation = Orientation::FRONT;
			loc = {240, 660};
			ID = MapItem::PLAYER1;
			handskill.push_back(HandSkill::BOMB);
		}
		Character(const char* frontImg, const char* backImg, const char* leftImg, const char* rightImg, const char* deadImg, MapItem playerID, Point2D location) { //fn is the image name 
			//load the image
			orientation = Orientation::FRONT;
			loc = location;
			explodeRange = 1;
			ID = playerID;
			RGBABitmap frontBitmap, backBitmap, leftBitmap, rightBitmap;

			frontBitmap.LoadPNG(frontImg);
			frontBitmap.Invert();
			orientationImg.push_back(frontBitmap);

			backBitmap.LoadPNG(backImg);
			backBitmap.Invert();
			orientationImg.push_back(backBitmap);

			leftBitmap.LoadPNG(leftImg);
			leftBitmap.Invert();
			orientationImg.push_back(leftBitmap);

			rightBitmap.LoadPNG(rightImg);
			rightBitmap.Invert();
			orientationImg.push_back(rightBitmap);

			deadBodyImg.LoadPNG(deadImg);
			deadBodyImg.Invert();

			handskill.push_back(HandSkill::BOMB);
		}
		void move(struct GameMapUnit (&gameMap)[15][17], Orientation direction);
		void draw() const;
		Cell getMapCoordinate(Point2D playerLocation);
		Cell getCoordinate(){return getMapCoordinate(loc);}
		bool checkInvincible();
		void giveInvincible();
		int getBlood(){return blood;}
		void addBlood(int value){blood += value;}
		void subBlood(int value){
			if(!checkInvincible()){ // make the player invincible for 2 sec after being hurt
				blood -= value; 
				giveInvincible();
			}
		}
		bool checkSurvival(){return survive;}
		void updateSurvival(){
			if(blood <= 0){
				survive = 0;
				deadTime = clock();
			}
		}
		clock_t getDeadTime(){return deadTime;}
		void addRange(int value){explodeRange += value;}
		void addSpeed(int value){speed += value;}
		int getBombNumber(){return bombNumber;}
		void addBombNumber(){bombNumber += 1;}
		void changeHandSkill(HandSkill skill){handskill.push_back(skill);}
		HandSkill getHandSkill(){return handskill.back();}
		void handSillUsed(){handskill.pop_back();}
		void harm(int value){blood -= value;}
		MapItem getID(){return ID;}
		int getSpeed(){return speed;}
		char* getCurrentWeapon();
};
