//
//  MoveMapMaker.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/25/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include "MoveMapMaker.h"
MoveMap MoveMapMaker::moveMap = MoveMapMaker::initializeMoveMap();

MoveMap MoveMapMaker::initializeMoveMap(){
    enum Directions {UP = -3, RIGHT = 1, DOWN = 3, LEFT = -1};
    
    MoveMap tempMoveMap = MoveMap(9,std::vector<int>());
    
    moveMap[0].push_back(RIGHT);
    moveMap[0].push_back(DOWN);
    
    moveMap[1].push_back(RIGHT);
    moveMap[1].push_back(DOWN);
    moveMap[1].push_back(LEFT);
    
    moveMap[2].push_back(DOWN);
    moveMap[2].push_back(LEFT);
    
    moveMap[3].push_back(UP);
    moveMap[3].push_back(RIGHT);
    moveMap[3].push_back(DOWN);
    
    moveMap[4].push_back(UP);
    moveMap[4].push_back(RIGHT);
    moveMap[4].push_back(DOWN);
    moveMap[4].push_back(LEFT);
    
    moveMap[5].push_back(UP);
    moveMap[5].push_back(DOWN);
    moveMap[5].push_back(LEFT);
    
    moveMap[6].push_back(UP);
    moveMap[6].push_back(RIGHT);
    
    moveMap[7].push_back(UP);
    moveMap[7].push_back(RIGHT);
    moveMap[7].push_back(LEFT);
    
    moveMap[8].push_back(UP);
    moveMap[8].push_back(LEFT);
    
    return tempMoveMap;
}