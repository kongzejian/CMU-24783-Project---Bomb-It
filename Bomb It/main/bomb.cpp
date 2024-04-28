#include "bomb.h"


bool Bomb::canDestroy(MapItem item){
    if(item == MapItem::FLOOR || item == MapItem::RED_ROADBLOCK || item == MapItem::BLUE_ROADBLOCK || item == MapItem::STREET_LAMP){
        return true;
    }
    return false;
}

clock_t Bomb::getPlaceTime(){
    return placeTime;
}

void Bomb::countDown(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].bombHere.push_back(MapItem::BOMB);
}

void Bomb::explode(GameMapUnit (&gameMap)[15][17], Map &map){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 5);

    gameMap[loc.y][loc.x].explodeHere.push_back(MapItem::EXPCENTER);
    if(!gameMap[loc.y][loc.x].playerHere.empty()){
        for(auto itt = gameMap[loc.y][loc.x].playerHere.begin(); itt != gameMap[loc.y][loc.x].playerHere.end(); ++itt){
            map.playerList[*itt].subBlood(1);
            map.playerList[*itt].updateSurvival();
        }
    }

    // left
    int x = loc.x - 1;
    int y = loc.y;
    while(1){
        if(!canDestroy(gameMap[y][x].backGround))
            break;
        if(!gameMap[y][x].playerHere.empty()){
            for(auto itt = gameMap[y][x].playerHere.begin(); itt != gameMap[y][x].playerHere.end(); ++itt){
                map.playerList[*itt].subBlood(1);
                map.playerList[*itt].updateSurvival();
            }
        }
        if(x == 1 || x > 1 && (!canDestroy(gameMap[y][x - 1].backGround)) || loc.x - x >= explodeRange){
            gameMap[y][x].explodeHere.push_back(MapItem::EXPENDL);
            if(gameMap[y][x].backGround != MapItem::FLOOR)
            {   
                gameMap[y][x].backGround = MapItem::FLOOR;
                switch (dis(gen))
                {
                case 1:
                    map.placePowerUp(MapItem::HEALTHCARE, {x, y});
                    break;
                case 2:
                    map.placePowerUp(MapItem::SNEAKER, {x, y});
                    break;
                case 3:
                    map.placePowerUp(MapItem::RANGE, {x, y});
                    break;
                case 4:
                    map.placePowerUp(MapItem::BOMBADD, {x, y});
                    break;
                case 5:
                    map.placePowerUp(MapItem::MINETOPICKUP, {x, y});
                    break;
                default:
                    break;
                }
            }
            break;
        }
        gameMap[y][x].backGround = MapItem::FLOOR;
        gameMap[y][x].explodeHere.push_back(MapItem::EXPMIDDLEH);
        x -= 1;
    }

    // right
    x = loc.x + 1;
    y = loc.y;
    while(1){
        if(!canDestroy(gameMap[y][x].backGround))
            break;
        if(!gameMap[y][x].playerHere.empty()){
            for(auto itt = gameMap[y][x].playerHere.begin(); itt != gameMap[y][x].playerHere.end(); ++itt){
                map.playerList[*itt].subBlood(1);
                map.playerList[*itt].updateSurvival();
            }
        }
        if(x == 16 || x < 16 && (!canDestroy(gameMap[y][x + 1].backGround)) || x - loc.x >= explodeRange){
            gameMap[y][x].explodeHere.push_back(MapItem::EXPENDR);
            if(gameMap[y][x].backGround != MapItem::FLOOR)
            {   
                gameMap[y][x].backGround = MapItem::FLOOR;
                switch (dis(gen))
                {
                case 1:
                    map.placePowerUp(MapItem::HEALTHCARE, {x, y});
                    break;
                case 2:
                    map.placePowerUp(MapItem::SNEAKER, {x, y});
                    break;
                case 3:
                    map.placePowerUp(MapItem::RANGE, {x, y});
                    break;
                case 4:
                    map.placePowerUp(MapItem::BOMBADD, {x, y});
                    break;
                case 5:
                    map.placePowerUp(MapItem::MINETOPICKUP, {x, y});
                    break;
                default:
                    break;
                }
            }
            break;
        }
        gameMap[y][x].backGround = MapItem::FLOOR;
        gameMap[y][x].explodeHere.push_back(MapItem::EXPMIDDLEH);
        x += 1;
    }

    // up
    x = loc.x;
    y = loc.y - 1;
    while(1){
        if(!canDestroy(gameMap[y][x].backGround))
            break;
        if(!gameMap[y][x].playerHere.empty()){
            for(auto itt = gameMap[y][x].playerHere.begin(); itt != gameMap[y][x].playerHere.end(); ++itt){
                map.playerList[*itt].subBlood(1);
                map.playerList[*itt].updateSurvival();
            }
        }
        if(y == 1 || y > 1 && (!canDestroy(gameMap[y - 1][x].backGround)) || loc.y - y >= explodeRange){
            gameMap[y][x].explodeHere.push_back(MapItem::EXPENDU);
            if(gameMap[y][x].backGround != MapItem::FLOOR)
            {   
                gameMap[y][x].backGround = MapItem::FLOOR;
                switch (dis(gen))
                {
                case 1:
                    map.placePowerUp(MapItem::HEALTHCARE, {x, y});
                    break;
                case 2:
                    map.placePowerUp(MapItem::SNEAKER, {x, y});
                    break;
                case 3:
                    map.placePowerUp(MapItem::RANGE, {x, y});
                    break;
                case 4:
                    map.placePowerUp(MapItem::BOMBADD, {x, y});
                    break;
                case 5:
                    map.placePowerUp(MapItem::MINETOPICKUP, {x, y});
                    break;
                default:
                    break;
                }
            }
            break;
        }
        gameMap[y][x].backGround = MapItem::FLOOR;
        gameMap[y][x].explodeHere.push_back(MapItem::EXPMIDDLEV);
        y -= 1;
    }

    // down
    x = loc.x;
    y = loc.y + 1;
    while(1){
        if(!canDestroy(gameMap[y][x].backGround))
            break;
        if(!gameMap[y][x].playerHere.empty()){
            for(auto itt = gameMap[y][x].playerHere.begin(); itt != gameMap[y][x].playerHere.end(); ++itt){
                map.playerList[*itt].subBlood(1);
                map.playerList[*itt].updateSurvival();
            }
        }
        if(y == 14 || y < 14 && (!canDestroy(gameMap[y + 1][x].backGround)) || y - loc.y >= explodeRange){
            gameMap[y][x].explodeHere.push_back(MapItem::EXPENDD);
            if(gameMap[y][x].backGround != MapItem::FLOOR)
            {   
                gameMap[y][x].backGround = MapItem::FLOOR;
                switch (dis(gen))
                {
                case 1:
                    map.placePowerUp(MapItem::HEALTHCARE, {x, y});
                    break;
                case 2:
                    map.placePowerUp(MapItem::SNEAKER, {x, y});
                    break;
                case 3:
                    map.placePowerUp(MapItem::RANGE, {x, y});
                    break;
                case 4:
                    map.placePowerUp(MapItem::BOMBADD, {x, y});
                    break;
                case 5:
                    map.placePowerUp(MapItem::MINETOPICKUP, {x, y});
                    break;
                default:
                    break;
                }
            }
            break;
        }
        gameMap[y][x].backGround = MapItem::FLOOR;
        gameMap[y][x].explodeHere.push_back(MapItem::EXPMIDDLEV);
        y += 1;
    }
}