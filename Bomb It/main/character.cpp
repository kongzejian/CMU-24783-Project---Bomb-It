#include "character.h"
#include <iostream>

void Character::move(GameMapUnit (&gameMap)[15][17], Orientation direction)
{
	if(canMove)
	{	
		Cell position = getMapCoordinate(loc);
		// Cell positionLR = {(loc.x + 30 - 1) / 60, (loc.y - 20 - 1) / 60};
		Cell positionLR = getMapCoordinate(loc);
		if(direction == Orientation::LEFT)
		{	
			if(orientation != Orientation::LEFT)
			{
				orientation = Orientation::LEFT;
			}
			else
			{	
				if(positionLR.x > 0)
				{	
					
					MapItem leftItem = gameMap[positionLR.y][positionLR.x - 1].backGround;
					// MapItem leftUpperItem = gameMap[position.y - 1][position.x - 1].backGround;
					// MapItem leftDownItem = gameMap[position.y + 1][position.x - 1].backGround;
					// if(leftUpperItem != MapItem::FLOOR)
					// {
					// 	if(loc.y < position.y * 60 + 40)
					// 	{	
					// 		loc.x = position.x * 60;
					// 		return ;
					// 	}
					// }
					// if(leftDownItem != MapItem::FLOOR)
					// {
					// 	if((loc.y + 60) > (position.y + 2) * 60)
					// 	{	
					// 		loc.x = position.x * 60;
					// 		return ;
					// 	}
					// }
	
					if((leftItem != MapItem::FLOOR || gameMap[positionLR.y][positionLR.x - 1].bombHere.size() > 0) && loc.x - positionLR.x * 60 < speed)
					{	
						// std::cout<< "distance: "<< loc.x - position.x * 60 <<std::endl;
						loc.x = positionLR.x * 60;
					}
					else
					{	
						loc.y = positionLR.y * 60 + 50;
						loc.x -= speed;
					}
				}
				else
				{
					loc.x = 0;
				}
				
			}
			
			
		}
		else if(direction == Orientation::RIGHT)
		{	
			
			if(orientation != Orientation::RIGHT)
			{
				orientation = Orientation::RIGHT;
			}
			else
			{		
					if(position.x < 16)
					{	
						
						MapItem rightItem = gameMap[position.y][position.x + 1].backGround;
						// MapItem rightUpperItem = gameMap[position.y - 1][position.x + 1].backGround;
						// MapItem rightDownItem = gameMap[position.y + 1][position.x + 1].backGround;
						// if(rightUpperItem != MapItem::FLOOR)
						// {
						// 	if(loc.y < position.y * 60 + 40)
						// 	{	
						// 		loc.x = position.x * 60;
						// 		return ;
						// 	}
						// }

						// if(rightDownItem != MapItem::FLOOR)
						// {
						// 	if((loc.y + 60) > (position.y + 2 ) * 60)
						// 	{	
						// 		loc.x = position.x * 60;
						// 		return ;
						// 	}
						// }
						//std::cout << (position.x + 1) * 60 - loc.x << std::endl;
						if((rightItem != MapItem::FLOOR || gameMap[position.y][position.x + 1].bombHere.size() > 0) && (position.x + 1) * 60 - (loc.x + 60) < speed)
						{	
							//std::cout << "distance: " << ((position.x + 1) * 60 - 30) - loc.x  <<std::endl;
							loc.x = (position.x + 1) * 60 - 60;
							
						}
						else
						{	loc.y = position.y *60 + 50;
							loc.x += speed;
						}
					}
					else
					{
						loc.x = 15 *60;
					}
					
			}
			
		}
		else if(direction == Orientation::FRONT)
		{	
			if(orientation!=Orientation::FRONT)
			{
				orientation = Orientation::FRONT;
			}
			else
			{
				if(position.y < 14)
				{
					MapItem downItem = gameMap[position.y + 1][position.x].backGround;
					// MapItem downRightItem = gameMap[position.y + 1][position.x - 1].backGround;
					// MapItem downLeftItem = gameMap[position.y + 1][position.x + 1].backGround;

					// if(downRightItem != MapItem::FLOOR)
					// {
					// 	if(loc.x < position.x * 60)
					// 	{	
					// 		loc.y = position.y *60 +60;
					// 		return ;
					// 	}
					// }

					// if(downLeftItem != MapItem::FLOOR )
					// {	
					// 	if((loc.x + 60) > (position.x + 1 ) * 60)
					// 	{	
					// 		loc.y = position.y *60 +60;
					// 		return ;
					// 	}
					// }
					if((downItem != MapItem::FLOOR || gameMap[position.y + 1][position.x].bombHere.size() > 0) && (position.y + 1) * 60 - loc.y < speed)
					{	
						loc.y = (position.y + 1) * 60;
					}
					else
					{	
						loc.x = position.x * 60;
						loc.y += speed;
						
					}	
				}
				else
				{
					loc.y = 14 * 60;
				}
				
			}
			
		}
		else
		{	
			
			if(orientation != Orientation::BACK)
			{
				orientation = Orientation::BACK;
			}
			else
			{	
				if(position.y > 0)
				{
					MapItem upItem = gameMap[position.y - 1][position.x].backGround;
					// MapItem upRightItem = gameMap[position.y - 1][position.x - 1].backGround;
					// MapItem upLeftItem = gameMap[position.y - 1][position.x + 1].backGround;

					// if(upRightItem != MapItem::FLOOR)
					// {
					// 	if(loc.x < position.x * 60)
					// 	{	
					// 		return ;
					// 	}
					// }

					// if(upLeftItem != MapItem::FLOOR)
					// {
					// 	if((loc.x + 60) > (position.x + 1 ) * 60)
					// 	{	
					// 		return ;
					// 	}
					// }

					if((upItem != MapItem::FLOOR || gameMap[position.y - 1][position.x].bombHere.size() > 0) && loc.y -  (position.y + 1) * 60 < speed)
					{	
						//std::cout<<"distance: "<< loc.y- ( ((position.y) * 60 + 30 )) << std::endl;
						loc.y = (position.y + 1 ) * 60;
					}
					else
					{	
						loc.x = position.x * 60;
						loc.y -= speed;
					}
				}
				else
				{
					loc.y = 60;
				}
			}
			
		}
		Cell new_position = getMapCoordinate(loc);
		if(new_position != position){
			//std::cout << "check" << std::endl;
			for (auto it = gameMap[position.y][position.x].playerHere.begin(); it != gameMap[position.y][position.x].playerHere.end(); ++it) {
				if(*it == ID){
					it = gameMap[position.y][position.x].playerHere.erase(it);
					break;
				}
            }
			gameMap[new_position.y][new_position.x].playerHere.push_back(ID);
		}
		//std:: cout << "x: " << new_position.x << std::endl;
		//std:: cout << "y: " << new_position.y << std::endl;
		//std:: cout << "x float: " << loc.x << std::endl;
		//std:: cout << "y float: " << loc.y << std::endl;
	}
}
char* Character::getCurrentWeapon(){
	if(handskill.size() > 0){
		if(handskill.back() == HandSkill::BOMB){
			return  "Bomb";
		}
		else if(handskill.back() == HandSkill::MINE){
			return  "Mine";
		}
	}
}


void Character::draw() const
{	
	if(survive){
		glRasterPos2i(loc.x, loc.y);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDrawPixels(orientationImg[static_cast<int>(orientation)].GetWidth(), 
					orientationImg[static_cast<int>(orientation)].GetHeight(), 
					GL_RGBA, 
					GL_UNSIGNED_BYTE, 
					orientationImg[static_cast<int>(orientation)].GetData());
	}
	else if((clock() - deadTime) / CLOCKS_PER_SEC < 2){
		glRasterPos2i(loc.x, loc.y);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDrawPixels(deadBodyImg.GetWidth(), 
					deadBodyImg.GetHeight(), 
					GL_RGBA, 
					GL_UNSIGNED_BYTE, 
					deadBodyImg.GetData());
	}
	else{}
}

Cell Character::getMapCoordinate(Point2D playerLocation)
{	
	Cell mapCoordinate;
	mapCoordinate.x = (playerLocation.x + 30 - 1) / 60;
    mapCoordinate.y = (playerLocation.y - 1) / 60;
	return mapCoordinate;
}

void Character::giveInvincible(){
	invincible = 1;
	invincibleTime = clock();
}

bool Character::checkInvincible(){
	if(invincible){
		if((clock() - invincibleTime) / CLOCKS_PER_SEC > 2){
			invincible = 0;
			return false;
		}
		else
			return true;
	}
	else
		return false;
}