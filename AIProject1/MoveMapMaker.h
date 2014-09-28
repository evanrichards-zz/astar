//
//  MoveMapMaker.h
//  AIProject1
//
//  Created by Evan Richards on 9/25/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#ifndef __AIProject1__MoveMapMaker__
#define __AIProject1__MoveMapMaker__

#include <stdio.h>
#include <vector>

typedef std::vector<std::vector<int> > MoveMap;

class MoveMapMaker{
private:
    static MoveMap initializeMoveMap();
    static MoveMap moveMap;
    
public:
    static MoveMap getMoveMap() { return moveMap; }
};
#endif /* defined(__AIProject1__MoveMapMaker__) */