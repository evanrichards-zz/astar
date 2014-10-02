//
//  a-star.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include "Node.h"

typedef std::vector<int> State;
typedef std::priority_queue<Node*, std::vector<Node*>, Node::CompStr> Frontier;

int zeroHeuristic(State node);
int displacedHeuristic(State node);
int manhattanDistanceHeuristic(State node);
int personalHeuristic(State node);
bool isGoalState(State state);
void printState(State state);
void outputStatistics(int numNodesVisited, Node* finalNode);
bool stateExistsInPath(State state, Node* parentNode);


int main (int argc, const char * argv[]){
    // Check for input error
    if(argc != 2){
        std::cout << "Requires 1 command line argument: integer for heuritic choice.\n";
        std::cout << "\t0: h(n) = 0\n";
        std::cout << "\t1: h(n) = Number of tiles displaced from the goal\n";
        std::cout << "\t2: h(n) = Sum of Manhattan (city-block) distances of all tiles from the goal\n";
        //TODO: REPLACE THIS LINE WITH DESCRIPTION
        std::cout << "\t3: h(n) = A novel heuristic of my own design\n";
        return 0;
    }
    int heuristicChoice = atoi(argv[1]);

    // Get initial state from input
    State initialState = State();
    for(int i = 0; i < 9; i++){
        int input;
        std::cin >> input;
        initialState.push_back(input);
    }
    
    // Define heuristic function pointer and assign it
    int (*heuristic)(State);
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
    
    Frontier frontier = Frontier();

    // Initialize the root.
    Node* root = new Node(heuristic(initialState), initialState, NULL);
    Node* currentNode = root;
    
    while (!isGoalState(currentNode->getState())) {
        // Expand the current node
        std::vector<State> successors = currentNode->getSuccessors();
        // Create nodes out of the new states
        for (int i = 0; i < successors.size(); i++) {
            if(stateExistsInPath(successors[i], currentNode)){
                // Don't add node, worse than already seen.
                continue;
            }
            Node* successorNode = new Node(heuristic(successors[i]),
                                           successors[i],
                                           currentNode);
            // Add new nodes to the frontier
            frontier.push(successorNode);
            currentNode->addChild(successorNode);
        }
        
        // Update currentNode
        currentNode = frontier.top();
        frontier.pop();
    }
    
    outputStatistics(Node::getTotalNumberOfNodes() - (int)frontier.size(),
                     currentNode);
    delete root;
}

int zeroHeuristic(State state){
    return 0;
}

int displacedHeuristic(State state){
    int numDisplaced = 0;
    for (int i = 0; i < state.size(); i++) {
        if(state[i] != i){
            numDisplaced++;
        }
    }
    return numDisplaced;
}

int manhattanDistanceHeuristic(State state){
    int sumOfDistances = 0;
    for (int i = 0; i < state.size(); i++) {
        int currentLocation = i;
        int finalLocation = state[i];
        while(currentLocation != finalLocation){
            if(finalLocation > currentLocation){
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

int personalHeuristic(State state){return 0;}

bool isGoalState(State state){
    for (int i = 0; i < state.size(); i++) {
        if(state[i] != i){
            return false;
        }
    }
    return true;
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

bool stateExistsInPath(State state, Node* parentNode){
    while(parentNode != NULL){
        if(parentNode->getState() == state){
            return true;
        }
        parentNode = parentNode->getParentNode();
    }
    return false;
}

void outputStatistics(int numNodesVisited, Node* finalNode){
    // TODO: Move into node class as describe
    std::cout << "V=" << numNodesVisited << std::endl;
    std::cout << "N=" << Node::getTotalNumberOfNodes() << std::endl;
    std::cout << "d=" << finalNode->getDepth() << std::endl;
    if(finalNode->getDepth() != 0) {
        std::cout << "b=" << pow(Node::getTotalNumberOfNodes(), 1.f/(finalNode->getDepth())) << std::endl;
    }
    std::vector<State> solution = std::vector<State>();
    while(finalNode != NULL){
        solution.push_back(finalNode->getState());
        finalNode = finalNode->getParentNode();
    }
    while(!solution.empty()){
        printState(solution.front());
        solution.pop_back();
    }
}