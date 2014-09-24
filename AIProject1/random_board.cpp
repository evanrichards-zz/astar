//
//  random_board.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <random>
#include <vector>

enum directions {UP = -3, RIGHT = 1, DOWN = 3, LEFT = -1};

typedef std::vector<std::vector<int>> MoveMap;
typedef std::vector<int> State;

void swap(State& state, int index1, int index2);
void printState(State state);
MoveMap initializeMoveMap();

int main(int argc, const char * argv[]) {
    if(argc != 3){
        std::cout << "Requires 2 command line arguments: integer for seed and integer for number of moves";
        return 0;
    }
    
    MoveMap moveMap = initializeMoveMap();

    srand(atoi(argv[1]));
    int numMoves =  atoi(argv[2]);

    State state = std::vector<int>(9, 0);
    int zeroLocation = -1;

    for (int i = 0; i < state.size(); i++) {
        std::cin >> state[i];
        if(zeroLocation == -1 && state[i] == 0){
            zeroLocation = i;
        }
    }
    for (int i = 0; i < numMoves; i++) {
        int numMoves = int(moveMap[zeroLocation].size());
        int step = moveMap[zeroLocation][rand()%numMoves];
        swap(state, zeroLocation, zeroLocation + step);
        zeroLocation = zeroLocation + step;
    }
    
    printState(state);
    return 0;
}

void printState(State state){
    for (int i = 0; i < 9 ; i+=3) {
        for(int j = i; j < i + 3; j++){
            std::cout << state[j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout<< std::endl;
}


void swap(State& state, int index1, int index2){
    int temp = state[index1];
    state[index1] = state[index2];
    state[index2] = temp;
}

MoveMap initializeMoveMap(){
    MoveMap moveMap = MoveMap(9,std::vector<int>());

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
    
    return moveMap;
}