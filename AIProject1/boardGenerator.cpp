//
//  boardGenerator.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/25/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//


#include "boardGenerator.h"

void BoardGenerator::swap(State& state, int index1, int index2){
    int temp = state[index1];
    state[index1] = state[index2];
    state[index2] = temp;
}
State BoardGenerator::getRandomBoard(int seed, int numMoves){
    State state = std::vector<int>(9, 0);
    // Get input for the initial state and store the zero location
    for (int i = 0; i < state.size(); i++) {
        state[i] = i;
    }
    return BoardGenerator::getRandomBoard(seed, numMoves, state);
}

State BoardGenerator::getRandomBoard(int seed, int numMoves, State initialState){
    
    srand(seed);
    // Holds where the zero is located
    int zeroLocation = 0;
    
    // Get input for the initial state and store the zero location
    for (int i = 0; i < initialState.size(); i++) {
        if(initialState[i] == 0){
            zeroLocation = i;
            break;
        }
    }
    MoveMap moveMapper = MoveMapMaker::getMoveMap();
    // Iterate over moves to randomize puzzle
    for (int i = 0; i < numMoves; i++) {
        int numMoves = int(moveMapper[zeroLocation].size());
        int step = moveMapper[zeroLocation][rand()%numMoves];
        swap(initialState, zeroLocation, zeroLocation + step);
        zeroLocation = zeroLocation + step;
    }
    return initialState;
};