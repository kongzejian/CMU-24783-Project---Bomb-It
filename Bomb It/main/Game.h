#include "map.h"
#include <vector>
#include "bitmap.h"
class Game
{
private:
	bool quit = false;
	Map map;
	RGBABitmap menu;
	int leftButton, middleButton, rightButton;
	int screenX, screenY;
	int mouseEvent;
	bool prevSpaceState = false;
	bool prevEnterState = false;
public:
    // State variables

    bool MustTerminate(void) const{
		return quit;
	}

	Game() 
	{	
		//load map ground item image
		std::vector<const char*> mapItemVector;
		mapItemVector.push_back("../Bomb it/image/mapItem/floor.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/green tree.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/red house.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/wall.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/blue road block.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/red road block.png");
		mapItemVector.push_back("../Bomb it/image/mapItem/street lamp.png");
		mapItemVector.push_back("../Bomb it/image/powerup/bomb.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeCenter.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeMiddleH.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeMiddleV.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeEndL.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeEndR.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeEndU.png");
		mapItemVector.push_back("../Bomb it/image/powerup/explodeEndD.png");
		mapItemVector.push_back("../Bomb it/image/powerup/healthcare.png");
		mapItemVector.push_back("../Bomb it/image/powerup/sneaker.png");
		mapItemVector.push_back("../Bomb it/image/powerup/range.png");
		mapItemVector.push_back("../Bomb it/image/powerup/bombAdd.png");
		mapItemVector.push_back("../Bomb it/image/powerup/mine_to_pick_up.png");
		mapItemVector.push_back("../Bomb it/image/powerup/mine_place.png");
		mapItemVector.push_back("../Bomb it/image/menu/statusBar.png");
		map.loadPNG(mapItemVector);
		//layer 1 image
		map.addPlayer(MapItem::PLAYER1,
					   "../Bomb it/image/character/blue character front.png", 
					   "../Bomb it/image/character/blue character back.png", 
					   "../Bomb it/image/character/blue character left.png", 
					   "../Bomb it/image/character/blue character right.png",
					   {240, 300});
		map.addPlayer(MapItem::PLAYER2,
					   "../Bomb it/image/character/red character front.png", 
					   "../Bomb it/image/character/red character back.png", 
					   "../Bomb it/image/character/red character left.png", 
					   "../Bomb it/image/character/red character right.png",
					   {720, 300});
		map.addPlayer(MapItem::PLAYER3,
					   "../Bomb it/image/character/green character front.png", 
					   "../Bomb it/image/character/green character back.png", 
					   "../Bomb it/image/character/green character left.png", 
					   "../Bomb it/image/character/green character right.png",
					   {240, 660});
		map.addPlayer(MapItem::PLAYER4,
					   "../Bomb it/image/character/yellow character front.png", 
					   "../Bomb it/image/character/yellow character back.png", 
					   "../Bomb it/image/character/yellow character left.png", 
					   "../Bomb it/image/character/yellow character right.png",
					   {720, 660});
		map.placePowerUp(MapItem::MINETOPICKUP,{6,10});
		menu.LoadPNG("../Bomb it/image/menu/menu.png");
    	menu.Invert();
		FsOpenWindow(300, 10, 1279, 900, 1); // width = 1020, height = 900
	}

	int Menu(void){
		FsPollDevice();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawPixels(menu.GetWidth(),
					menu.GetHeight(),
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					menu.GetData());
		mouseEvent = FsGetMouseEvent(leftButton, middleButton, rightButton, screenX, screenY);
		if(mouseEvent == FSMOUSEEVENT_LBUTTONDOWN && screenX >= 790 && screenX <= 1010 && screenY >= 610 && screenY <= 670)
		{
			return 1;
		}
		FsSwapBuffers();
		FsSleep(10);
		return 0;
	}

    void RunOneStep(void){
		FsPollDevice();
		auto Key = FsInkey();

		bool currentSpaceState = (0 != FsGetKeyState(FSKEY_SPACE));
		bool spaceKeyPressed = (currentSpaceState && !prevSpaceState);
		prevSpaceState = currentSpaceState;

		bool currentEnterState = (0 != FsGetKeyState(FSKEY_ENTER));
		bool enterKeyPressed = (currentEnterState && !prevEnterState);
		prevEnterState = currentEnterState;



		if(0 != FsGetKeyState(FSKEY_W))
			map.movePlayer(MapItem::PLAYER1, Orientation::BACK);
		if(0 != FsGetKeyState(FSKEY_A))
			map.movePlayer(MapItem::PLAYER1, Orientation::LEFT);
		if(0 != FsGetKeyState(FSKEY_S))
			map.movePlayer(MapItem::PLAYER1, Orientation::FRONT);
		if(0 != FsGetKeyState(FSKEY_D))
			map.movePlayer(MapItem::PLAYER1, Orientation::RIGHT);
		if (spaceKeyPressed)
			map.placeWeapon(MapItem::PLAYER1);
		if(0 != FsGetKeyState(FSKEY_UP))
			map.movePlayer(MapItem::PLAYER2, Orientation::BACK);
		if(0 != FsGetKeyState(FSKEY_LEFT))
			map.movePlayer(MapItem::PLAYER2, Orientation::LEFT);
		if(0 != FsGetKeyState(FSKEY_DOWN))
			map.movePlayer(MapItem::PLAYER2, Orientation::FRONT);
		if(0 != FsGetKeyState(FSKEY_RIGHT))
			map.movePlayer(MapItem::PLAYER2, Orientation::RIGHT);
		if (enterKeyPressed)
			map.placeWeapon(MapItem::PLAYER2);
		
		map.autoDecision(MapItem::PLAYER3);
		map.autoDecision(MapItem::PLAYER4);

		if(FSKEY_ESC == Key){
			quit = true;
		}
	}

    void Draw(void){
		glClearColor(1.0f, 0.79f, 0.82f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		map.drawSB();
		map.draw();
		FsSwapBuffers();
		FsSleep(10);
	}
};