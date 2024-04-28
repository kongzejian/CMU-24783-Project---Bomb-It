#include "weapon.h"

clock_t weapon::getPlaceTime(){
    return placeTime;
}

void weapon::countDown(struct GameMapUnit (&gameMap)[15][17]){
    
}

void weapon::shrink(clock_t __cdecl currentTime,GameMapUnit (&gameMap)[15][17]){

}
void realMine::shrink(clock_t __cdecl currentTime, GameMapUnit (&gameMap)[15][17]){
    if((currentTime - placeTime) / CLOCKS_PER_SEC == 1){
        if (gameMap[loc.y][loc.x].weaponHere.size() != 0) {
            gameMap[loc.y][loc.x].weaponHere.pop_back();
        }
    }
}

void realMine::countDown(GameMapUnit (&gameMap)[15][17]){
    gameMap[loc.y][loc.x].weaponHere.push_back(MapItem::MINEPLACE);
}

void weapon::effect(Character &player){

}

void realMine::effect(Character &player){
    player.harm(1);
}

bool weapon::checkStepOn(std::map<MapItem, Character>& playerList, GameMapUnit (&gameMap)[15][17]){
    for(auto it = playerList.begin(); it != playerList.end(); ++it){
        Cell playerLoc = it->second.getCoordinate();
        if(playerLoc.x == loc.x && playerLoc.y == loc.y && playerID != it->second.getID()){
            effect(it->second);
            if (gameMap[loc.y][loc.x].weaponHere.size() != 0) {
            gameMap[loc.y][loc.x].weaponHere.pop_back();
            }
            return true;
        }
    }
    return false;
}
