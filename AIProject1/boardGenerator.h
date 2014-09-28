//
//  boardGenerator.h
//  AIProject1
//
//  Created by Evan Richards on 9/25/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#ifndef __AIProject1__boardGenerator__
#define __AIProject1__boardGenerator__
#include <stdio.h>
#include <vector>
#include <random>
#include "MoveMapMaker.h"

typedef std::vector<int> State;

class BoardGenerator {
private:
    static void swap(State& state, int index1, int index2);
public:
    static State getRandomBoard(int seed, int numMoves);
    static State getRandomBoard(int seed, int numMoves, State initialState);

};
#endif /* defined(__AIProject1__boardGenerator__) */
