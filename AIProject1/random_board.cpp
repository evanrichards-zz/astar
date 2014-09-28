//
//  random_board.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Takes 2 numbers on the command line:
//      Int for seed to RNG
//      Int for number of moves
//
//  Given an input of a 3x3 matrix with numbers 0-8, this randomly swaps
//      the location of the 0 with an adjacent tile to make a random output.

#include <iostream>
#include <vector>
#include "boardGenerator.h"

typedef std::vector<int> State;

void printState(State state);

int main(int argc, const char * argv[]) {
//int temp(int argc, const char * argv[]) {
    // Check for bad input
    if(argc != 3){
        std::cout << "Requires 2 command line arguments: integer for seed and integer for number of moves";
        return 0;
    }
    // Use the inputs, seed the RNG and store the number of moves
    int seed = atoi(argv[1]);
    int numMoves = atoi(argv[2]);
    
    // Holds the initial state
    State initialState = State(9, 0);

    // Get input for the initial state and store the zero location
    for (int i = 0; i < initialState.size(); i++) {
        std::cin >> initialState[i];
    }
    
    printState(BoardGenerator::getRandomBoard(seed, numMoves, initialState));
    
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