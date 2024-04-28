#include "map.h"

MapItem Map1[15][17] = {
        {MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::RED_ROADBLOCK,MapItem::FLOOR,MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::FLOOR,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::BLUE_ROADBLOCK,MapItem::RED_ROADBLOCK,MapItem::RED_HOUSE,MapItem::STREET_LAMP,MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::RED_ROADBLOCK,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::RED_ROADBLOCK,MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::WALL,MapItem::GREEN_TREE,MapItem::WALL,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::WALL,MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::STREET_LAMP,MapItem::WALL,MapItem::WALL,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::STREET_LAMP,MapItem::RED_ROADBLOCK,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::WALL,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::STREET_LAMP,MapItem::WALL,MapItem::WALL,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::WALL,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::RED_ROADBLOCK,MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::BLUE_ROADBLOCK,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::STREET_LAMP,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::RED_HOUSE,MapItem::STREET_LAMP,MapItem::RED_HOUSE,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::BLUE_ROADBLOCK,MapItem::RED_HOUSE,MapItem::WALL,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::STREET_LAMP,MapItem::FLOOR,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_ROADBLOCK,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::RED_HOUSE,MapItem::WALL,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::WALL,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::WALL,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::FLOOR,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::STREET_LAMP,MapItem::RED_HOUSE,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::FLOOR,MapItem::WALL,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::WALL,MapItem::FLOOR,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_ROADBLOCK,MapItem::FLOOR,MapItem::RED_ROADBLOCK,MapItem::STREET_LAMP,MapItem::RED_HOUSE,MapItem::WALL,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::BLUE_ROADBLOCK,MapItem::STREET_LAMP,MapItem::RED_ROADBLOCK,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::BLUE_ROADBLOCK,MapItem::RED_HOUSE,MapItem::FLOOR,MapItem::FLOOR,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::RED_HOUSE,MapItem::GREEN_TREE,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::RED_ROADBLOCK,MapItem::RED_HOUSE,MapItem::BLUE_ROADBLOCK,MapItem::FLOOR,MapItem::GREEN_TREE},
        {MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE,MapItem::GREEN_TREE},
};

int Map::getPlayerBombUpLimit(MapItem playerID)
{
    return playerList[playerID].getBombNumber();
}


int Map::checkBombNumberForOnePlayer(MapItem playerID)
{
    int bombNumber = 0;
    for(int i = 0; i < bombList.size(); i++){
        auto bomb = bombList[i];
        if(bomb.belongTo() == playerID){
            bombNumber += 1;
        }
    }

    return bombNumber;
}

void Map::loadPNG(std::vector<const char*>imgPaths)
{
    RGBABitmap tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[0]);
    tmpBitmap.Invert();
    textures[MapItem::FLOOR] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[1]);
    tmpBitmap.Invert();
    textures[MapItem::GREEN_TREE] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[2]);
    tmpBitmap.Invert();
    textures[MapItem::RED_HOUSE] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[3]);
    tmpBitmap.Invert();
    textures[MapItem::WALL] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[4]);
    tmpBitmap.Invert();
    textures[MapItem::BLUE_ROADBLOCK] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[5]);
    tmpBitmap.Invert();
    textures[MapItem::RED_ROADBLOCK] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[6]);
    tmpBitmap.Invert();
    textures[MapItem::STREET_LAMP] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[7]);
    tmpBitmap.Invert();
    textures[MapItem::BOMB] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[8]);
    tmpBitmap.Invert();
    textures[MapItem::EXPCENTER] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[9]);
    tmpBitmap.Invert();
    textures[MapItem::EXPMIDDLEH] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[10]);
    tmpBitmap.Invert();
    textures[MapItem::EXPMIDDLEV] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[11]);
    tmpBitmap.Invert();
    textures[MapItem::EXPENDL] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[12]);
    tmpBitmap.Invert();
    textures[MapItem::EXPENDR] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[13]);
    tmpBitmap.Invert();
    textures[MapItem::EXPENDU] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[14]);
    tmpBitmap.Invert();
    textures[MapItem::EXPENDD] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[15]);
    tmpBitmap.Invert();
    textures[MapItem::HEALTHCARE] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[16]);
    tmpBitmap.Invert();
    textures[MapItem::SNEAKER] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[17]);
    tmpBitmap.Invert();
    textures[MapItem::RANGE] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[18]);
    tmpBitmap.Invert();
    textures[MapItem::BOMBADD] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[19]);
    tmpBitmap.Invert();
    textures[MapItem::MINETOPICKUP] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[20]);
    tmpBitmap.Invert();
    textures[MapItem::MINEPLACE] = tmpBitmap;

    tmpBitmap.LoadPNG(imgPaths[21]);
    tmpBitmap.Invert();
    statusBarImg = tmpBitmap;

    gameOver.LoadPNG( "../Bomb it/image/menu/over.png");
    gameOver.Invert();
}

void Map::draw()
{   
    if(checkgameOver() != true){
            for(int x = 0; x < MAP_HEIGHT; x++){
                for(int y = 0; y < MAP_WIDTH; y++){
                        GameMap[x][y].bombHere.clear();
                        GameMap[x][y].explodeHere.clear();
                }
            }
            checkBomb();
            checkPowerUp();
            checkWeaponTimeToinvisibility();
            checkWeapon();
            std::vector<int> drawY;
            for(int x = 0; x < MAP_HEIGHT; x++){
                drawY.clear();
                for(int y = 0; y < MAP_WIDTH; y++){
                    glRasterPos2i(y*60, (x+1)*60-1);
                    glEnable(GL_BLEND);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    glDrawPixels(textures[GameMap[x][y].backGround].GetWidth(),
                                textures[GameMap[x][y].backGround].GetHeight(),
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                textures[GameMap[x][y].backGround].GetData());
                    if(!GameMap[x][y].playerHere.empty())
                        drawY.push_back(y);
                    for(auto it = GameMap[x][y].bombHere.begin(); it != GameMap[x][y].bombHere.end(); ++it){
                        glDrawPixels(textures[*it].GetWidth(),
                                textures[*it].GetHeight(),
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                textures[*it].GetData());
                    }

                    for(auto it = GameMap[x][y].explodeHere.begin(); it != GameMap[x][y].explodeHere.end(); ++it){
                        glDrawPixels(textures[*it].GetWidth(),
                                textures[*it].GetHeight(),
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                textures[*it].GetData());
                    }

                    for(auto it = GameMap[x][y].weaponHere.begin(); it != GameMap[x][y].weaponHere.end(); ++it){
                        glDrawPixels(textures[*it].GetWidth(),
                                textures[*it].GetHeight(),
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                textures[*it].GetData());
                    }

                    for(int i = 0 ; i < GameMap[x][y].powerUpHere.size(); i++){
                        glDrawPixels(textures[GameMap[x][y].powerUpHere[i]].GetWidth(),
                                textures[GameMap[x][y].powerUpHere[i]].GetHeight(),
                                GL_RGBA,
                                GL_UNSIGNED_BYTE,
                                textures[GameMap[x][y].powerUpHere[i]].GetData());
                    }
                }
                for(auto it = drawY.begin(); it != drawY.end(); ++it){
                    for(auto itt = GameMap[x][*it].playerHere.begin(); itt != GameMap[x][*it].playerHere.end(); ++itt){
                        if(playerList[*itt].checkSurvival() || (clock() - playerList[*itt].getDeadTime()) / CLOCKS_PER_SEC < 2)
                            playerList[*itt].draw();
                        else{
                            itt = GameMap[x][*it].playerHere.erase(itt);
                            if(GameMap[x][*it].playerHere.end() == itt)
                                break;
                        }
                    }
                }
            }
    }
    else{
        glClearColor(0, 0, 0, 0);
        glRasterPos2i(0, 899);
		glDrawPixels(gameOver.GetWidth(),
					gameOver.GetHeight(),
					GL_RGBA,
					GL_UNSIGNED_BYTE,
					gameOver.GetData());
    }
    // playerList[MapItem::PLAYER1].draw();
}

void Map::createMap()
{   
    
    for (int i = 0; i < MAP_HEIGHT; i++)
    {
        for (int j = 0; j < MAP_WIDTH; j++)
        {
            GameMap[i][j].backGround = Map1[i][j];
        }
    }
    std::vector<std::vector<bool>> visitedP3(15, std::vector<bool>(17, false));
    visitedMap.insert(std::make_pair(MapItem::PLAYER3, visitedP3));
    std::vector<std::vector<bool>> visitedP4(15, std::vector<bool>(17, false));
    visitedMap.insert(std::make_pair(MapItem::PLAYER4, visitedP4));

    
	std::vector<Orientation> directionsP3 = {Orientation::LEFT, Orientation::RIGHT, Orientation::BACK, Orientation::FRONT};
    priorityDir.insert(std::make_pair(MapItem::PLAYER3, directionsP3));
    std::vector<Orientation> directionsP4 = {Orientation::LEFT, Orientation::RIGHT, Orientation::BACK, Orientation::FRONT};
    priorityDir.insert(std::make_pair(MapItem::PLAYER4, directionsP4));
}

void Map::addPlayer(MapItem playerID, char* frontImg, const char* backImg, const char* leftImg, const char* rightImg, Point2D location)
{
    Character player(frontImg, backImg, leftImg, rightImg, "../Bomb it/image/character/character dead.png", playerID, location);
    playerList.insert(std::make_pair(playerID, player));
    GameMap[(player.loc.y - 1) / 60][(player.loc.x + 30 - 1) / 60].playerHere.push_back(playerID);
}

void Map::movePlayer(MapItem playerID, Orientation orientation){
    if(!playerList[playerID].checkSurvival())
        return;
    playerList[playerID].move(GameMap, orientation);
}

void Map::placeBomb(MapItem playerID){
    Cell loc = {(playerList[playerID].loc.x + 30 - 1) / 60, (playerList[playerID].loc.y - 1) / 60};
    if( checkBombNumberForOnePlayer(playerID) < getPlayerBombUpLimit(playerID) && GameMap[loc.y][loc.x].bombHere.size() == 0){
        Bomb bomb(playerList[playerID].explodeRange, loc, playerID);
        bomb.countDown(GameMap);
        bombList.push_back(bomb);
    }
}

void Map::placeMine(MapItem playerID){
    Cell loc = {(playerList[playerID].loc.x + 30 - 1) / 60, (playerList[playerID].loc.y - 1) / 60};
    weapon* m = new realMine(loc, playerID);
    m->countDown(GameMap);
    weaponList.push_back(m);
}


void Map::checkBomb(){
    for (auto it = bombList.begin(); it != bombList.end(); ++it) {
        
        if((clock() - it -> getPlaceTime()) / CLOCKS_PER_SEC < 3)
            it -> countDown(GameMap);
        else if((clock() - it -> getPlaceTime()) / CLOCKS_PER_SEC < 4){
            explosionSoundPlayer.PlayBackground(explosionSound, true);
            it -> explode(GameMap, *this);
        }
        else{
            it = bombList.erase(it);
            if(it == bombList.end())
                break;
        }
    }
}


void Map::checkWeaponTimeToinvisibility(){
    for(int i = 0; i < weaponList.size(); i++){
        auto it = weaponList[i];
        it->shrink(clock(),GameMap);
    }
}

void Map::checkPowerUp(){
    for (auto it = powerUpList.begin(); it != powerUpList.end(); ) {
        PowerUp* powerUp = *it; 
        if(powerUp -> checkPlayerPickUp(playerList)){
            powerUp -> pickedUp(GameMap);
            delete powerUp;
            it = powerUpList.erase(it);
        }
        else{
            ++it;
        }
    }
}

void Map::checkWeapon(){
    for(auto it = weaponList.begin(); it != weaponList.end(); ){
        weapon* w = *it; 
        if(w ->checkStepOn(playerList, GameMap)){
            delete w;
            it = weaponList.erase(it);
        }
        else{
            ++it;
        }
    }
}

void Map::placePowerUp(MapItem powerUpItem,Cell loc){
    if(powerUpItem == MapItem::RANGE){
        PowerUp* r = new Range(loc);
        r->initialized(GameMap);
        powerUpList.push_back(r);
    }
    else if(powerUpItem == MapItem::HEALTHCARE){
        PowerUp* h = new HealthCare(loc);
        h->initialized(GameMap);
        powerUpList.push_back(h);
    }
    else if(powerUpItem == MapItem::SNEAKER){
        PowerUp* s = new Sneaker(loc);
        s->initialized(GameMap);
        powerUpList.push_back(s);
    }
    else if(powerUpItem == MapItem::BOMBADD){
        PowerUp* b = new BombAdd(loc);
        b->initialized(GameMap);
        powerUpList.push_back(b);
    }
    else if(powerUpItem == MapItem::MINETOPICKUP){
        PowerUp* m = new Mine(loc);
        m->initialized(GameMap);
        powerUpList.push_back(m);
    }

    // add more items in the future
}

void Map::placeWeapon(MapItem playerID){
    if(!playerList[playerID].checkSurvival())
        return;
    if(playerList[playerID].getHandSkill() == HandSkill::BOMB){
        if(checkBombNumberForOnePlayer(playerID) < getPlayerBombUpLimit(playerID))
			{ 
				placeBomb(playerID);
                return;
			}
    }
    else if(playerList[playerID].getHandSkill() == HandSkill::MINE){
        placeMine(playerID);
        playerList[playerID].handSillUsed();
        return;
    }
}

void Map::drawSB(){
    glRasterPos2i(1020, 900-1);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDrawPixels(statusBarImg.GetWidth(),
                statusBarImg.GetHeight(),
                GL_RGBA,
                GL_UNSIGNED_BYTE,
                statusBarImg.GetData());

    char buffer[50]; // Make sure it's large enough to hold the string

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER1].getBlood());
    glRasterPos2i(1065, 628); // sets position
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer); // there are other font sizes

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER1].getBombNumber());
    glRasterPos2i(1205, 488);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%s", playerList[MapItem::PLAYER1].getCurrentWeapon());
    glRasterPos2i(1135, 630);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);


    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER2].getBlood());
    glRasterPos2i(1065, 213); // sets position
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer); // there are other font sizes

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER2].getBombNumber());
    glRasterPos2i(1205, 73);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%s", playerList[MapItem::PLAYER2].getCurrentWeapon());
    glRasterPos2i(1135, 215);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER3].getBlood());
    glRasterPos2i(1065, 835); // sets position
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer); // there are other font sizes

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER3].getBombNumber());
    glRasterPos2i(1205, 695);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%s", playerList[MapItem::PLAYER3].getCurrentWeapon());
    glRasterPos2i(1135, 837);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER4].getBlood());
    glRasterPos2i(1065, 420); // sets position
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer); // there are other font sizes

    std::sprintf(buffer, "%d", playerList[MapItem::PLAYER4].getBombNumber());
    glRasterPos2i(1205, 280);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    std::sprintf(buffer, "%s", playerList[MapItem::PLAYER4].getCurrentWeapon());
    glRasterPos2i(1135, 422);
    glColor3ub(255, 255, 255);
    YsGlDrawFontBitmap20x32(buffer);

    return;
}

bool Map::checkgameOver(){
    int live = 4;
    for(auto it = playerList.begin(); it != playerList.end(); ++it){
        if(it->second.getBlood() <= 0){
            live -= 1;
        }
    }
    return live == 1;
}


void Map::autoDecision(MapItem playerID){

    int row = (playerList[playerID].loc.y - 1) / 60;
    int col = (playerList[playerID].loc.x + 30 - 1) / 60;
    visitedMap[playerID][row][col] = true;

    

    Cell notFound{-1, -1};
    Cell foundBombLoc = hasBombInRange(playerID);
    if(notFound != foundBombLoc){

        if(row < foundBombLoc.x){
            if(col < foundBombLoc.y){
                priorityDir[playerID] = {Orientation::LEFT, Orientation::BACK, Orientation::FRONT, Orientation::RIGHT};
            }
            else if(col > foundBombLoc.y){
                priorityDir[playerID] = {Orientation::RIGHT, Orientation::BACK, Orientation::FRONT, Orientation::LEFT};
            }
            else{
                priorityDir[playerID] = {Orientation::BACK, Orientation::LEFT, Orientation::RIGHT, Orientation::FRONT};
            }
        }
        else if(row > foundBombLoc.x){
            if(col < foundBombLoc.y){
                priorityDir[playerID] = {Orientation::LEFT, Orientation::FRONT, Orientation::BACK, Orientation::RIGHT};
            }
            else if(col > foundBombLoc.y){
                priorityDir[playerID] = {Orientation::LEFT, Orientation::FRONT, Orientation::BACK, Orientation::RIGHT};
            }
            else{
                priorityDir[playerID] = {Orientation::FRONT, Orientation::LEFT, Orientation::RIGHT, Orientation::BACK};
            }
        }
        else{
            if(col < foundBombLoc.y){
                priorityDir[playerID] = {Orientation::LEFT, Orientation::BACK, Orientation::FRONT, Orientation::RIGHT};
            }
            else if(col > foundBombLoc.y){
                priorityDir[playerID] = {Orientation::RIGHT, Orientation::BACK, Orientation::FRONT, Orientation::LEFT};
            }
            else{ // anyway works
            }
        }
    }

    int walkable = 0;
    for (int i = 0; i < 4; i++) {
        int newRow;
        int newCol;
        switch (priorityDir[playerID][i]){
            case Orientation::LEFT:
                newRow = row;
                newCol = col - 1;
                break;
            case Orientation::RIGHT:
                newRow = row;
                newCol = col + 1;
                break;
            case Orientation::BACK:
                newRow = row - 1;
                newCol = col;
                break;
            case Orientation::FRONT:
                newRow = row + 1;
                newCol = col;
                break;
            default:
                break;
        }
        if (isValidMove(visitedMap[playerID], newRow, newCol)){
            walkable = 1;
            movePlayer(playerID, priorityDir[playerID][i]);
            int updatedRow = (playerList[playerID].loc.y - 1) / 60;
            int updatedCol = (playerList[playerID].loc.x + 30 - 1) / 60;
            if(updatedRow != row || updatedCol != col){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::shuffle(priorityDir[playerID].begin(), priorityDir[playerID].end(), gen);
                if(hasPlayerInRange(playerID)){
                    placeWeapon(playerID);
                }
            }
            break;
        }
    }
    if(!walkable){
        for (auto& row : visitedMap[playerID]) {
            row.assign(row.size(), false);
        }
        std::random_device rd;
        std::mt19937 gen(rd());
        std::shuffle(priorityDir[playerID].begin(), priorityDir[playerID].end(), gen);
    }
}

bool Map::isValidMove(const std::vector<std::vector<bool>>& visited, int row, int col) {
    int rows = 15;
    int cols = 17;
    // Check if the move is within the boundaries of the grid
    if (row < 0 || col < 0 || row >= rows || col >= cols) {
        return false;
    }
    // Check if the move is not an obstacle and not visited before
    return GameMap[row][col].backGround == MapItem::FLOOR && GameMap[row][col].explodeHere.empty() && GameMap[row][col].bombHere.empty() && !visited[row][col];
}

bool Map::hasPlayerInRange(MapItem playerID){
    int row = (playerList[playerID].loc.y - 1) / 60;
    int col = (playerList[playerID].loc.x + 30 - 1) / 60;
    for(int i = row - 2; i <= row + 2; i++){
        for(int j = col - 2; j <= col + 2; j++){
            if(i == row && j == col)
                continue;
            if(i >= 0 && j >= 0 && i < 15 && j < 17)
                if(!GameMap[i][j].playerHere.empty())
                    return true;
        }
    }
    return false;
}

Cell Map::hasBombInRange(MapItem playerID){
    int row = (playerList[playerID].loc.y - 1) / 60;
    int col = (playerList[playerID].loc.x + 30 - 1) / 60;
    for(int i = row - 2; i <= row + 2; i++){
        for(int j = col - 2; j <= col + 2; j++){
            if(i >= 0 && j >= 0 && i < 15 && j < 17)
                if(!GameMap[i][j].bombHere.empty())
                    return {i, j};
        }
    }
    return {-1, -1};
}