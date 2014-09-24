//
//  a-star.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Node.h"

typedef  std::vector<int> State;

int zeroHeuristic(Node* node);
int displacedHeuristic(Node* node);
int manhattanDistanceHeuristic(Node* node);
int personalHeuristic(Node* node);

int main (int argc, const char * argv[]){
    // Check for input error
    if(argc != 2){
        std::cout << "Requires 1 command line argument: integer for heuritic choice";
        std::cout << "\t0: h(n) = 0\n";
        std::cout << "\t1: h(n) = Number of tiles displaced from the goal\n";
        std::cout << "\t2: h(n) = Sum of Manhattan (city-block) distances of all tiles from the goal\n";
        //TODO: REPLACE THIS LINE WITH DESCRIPTION
        std::cout << "\t3: h(n) = A novel heuristic of my own design\n";
    }
    int heuristicChoice = atoi(argv[1]);
    
    // Define heuristic function pointer and assign it
    int (*heuristic)(Node*);
    switch (heuristicChoice) {
        case 0:
            heuristic = &zeroHeuristic;
            break;
        case 1:
            heuristic = &displacedHeuristic;
            break;
        case 2:
            heuristic = &manhattanDistanceHeuristic;
            break;
        case 3:
            heuristic = &personalHeuristic;
            break;
        default:
            break;
    }
    
}

int zeroHeuristic(Node* node){
    return 0;
}

int displacedHeuristic(Node* node){
    int numDisplaced = 0;
    for (int i = 0; i < node->state.size(); i++) {
        if(node->state[i] != i){
            numDisplaced++;
        }
    }
    return numDisplaced;
}

int manhattanDistanceHeuristic(Node* node){
    int sumOfDistances = 0;
    for (int i = 0; i < node->state.size(); i++) {
        int currentLocation = i;
        int finalLocation = node->state[i];
        while(currentLocation != finalLocation){
            if(finalLocation > currentLocation){
                // TODO make can't move right because on wall clearer
                if(currentLocation % 3 == 2 || abs(currentLocation + 3 - finalLocation) < abs(currentLocation + 1 - finalLocation)){
                    currentLocation += 3;
                } else {
                    currentLocation += 1;
                }
            } else {
                if(currentLocation % 3 == 0 || abs(currentLocation - 3 - finalLocation) < abs(currentLocation - 1 - finalLocation)){
                    currentLocation -= 3;
                } else {
                    currentLocation -= 1;
                }
            }
            sumOfDistances++;
        }
    }
    return sumOfDistances;
}