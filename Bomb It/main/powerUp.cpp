#include "powerUp.h"



void PowerUp::pickedUp(struct GameMapUnit (&gameMap)[15][17]){

    gameMap[loc.y][loc.x].powerUpHere.pop_back();
}

bool PowerUp::checkPlayerPickUp(std::map<MapItem, Character>& playerList){
    for(auto it = playerList.begin(); it != playerList.end(); ++it){
        Cell playerLoc = it->second.getCoordinate();
        if(playerLoc.x == loc.x && playerLoc.y == loc.y){
            effect(it->second);
            return true;
        }
    }
    return false;
}


void PowerUp::effect(Character &player){

}

void PowerUp::initialized(GameMapUnit (&gameMap)[15][17]){
    
}

void HealthCare::effect(Character &player){
    int blood = player.getBlood();
    if(blood < 100){
        player.addBlood(1);
    }
}

void HealthCare::initialized(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].powerUpHere.push_back(MapItem::HEALTHCARE);
}

void Range::effect(Character &player){
    player.addRange(1);
}

void Range::initialized(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].powerUpHere.push_back(MapItem::RANGE);
}

void Sneaker::effect(Character &player){
    if(player.getSpeed() < 10){
        player.addSpeed(5);
    }
}

void Sneaker::initialized(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].powerUpHere.push_back(MapItem::SNEAKER);
}

void BombAdd::initialized(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].powerUpHere.push_back(MapItem::BOMBADD);
}

void BombAdd::effect(Character &player){
    player.addBombNumber();
}

void Mine::initialized(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].powerUpHere.push_back(MapItem::MINETOPICKUP);
}

void Mine::effect(Character &player){
    player.changeHandSkill(HandSkill::MINE);
}
