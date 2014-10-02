//
//  a-star.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

// Bring in random generation
// loop a*
// write to file

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <fstream>
#include <map>
#include "Node.h"
#include "boardGenerator.h"
#include "MoveMapMaker.h"


typedef std::vector<int> State;
typedef std::priority_queue<Node*, std::vector<Node*>, Node::CompStr> Frontier;
typedef std::map<State,int> Explored;

int zeroHeuristic(State node);
int displacedHeuristic(State node);
int manhattanDistanceHeuristic(State node);
int personalHeuristic(State node);
bool isGoalState(State state);
void outputStatistics(int numNodesVisited, Node* finalNode, int heuristicChoice);
bool stateExistsInPath(State state, Node* parentNode);

int main (int argc, const char * argv[]){
    // Check for input error
    for (int heuristicChoice = 0; heuristicChoice < 3; heuristicChoice++) {
        // Define heuristic function pointer and assign it
        int (*heuristic)(State) = NULL;
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
        for (int loop = 0; loop < 100; loop++) {
        // Get initial state from input
            int seed = rand();
            printf("Heuristc %d Loop #%d seed: %d\n", heuristicChoice, loop, seed);

            State initialState = BoardGenerator::getRandomBoard(seed, 100);

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
            // TODO: Alter to remove cast.
            outputStatistics(Node::getTotalNumberOfNodes() - (int)frontier.size(),
                             currentNode,
                             heuristicChoice);
            delete root;
            Node::resetStaticId();
        }
    }
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

int personalHeuristic(State state){return 0;}

bool isGoalState(State state){
    for (int i = 0; i < state.size(); i++) {
        if(state[i] != i){
            return false;
        }
    }
    return true;
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


void outputStatistics(int numNodesVisited, Node* finalNode, int heuristicChoice){
    std::string filename = "astarstats";
    switch (heuristicChoice) {
        case 0:
            filename += "0";
            break;
        case 1:
            filename += "1";
            break;
        case 2:
            filename += "2";
            break;
        default:
            break;
    }
    filename += ".csv";
    std::ofstream output (filename, std::ios::app);
    output << numNodesVisited << ",";
    output << Node::getTotalNumberOfNodes() << ",";
    output << finalNode->getDepth() << ",";
    if(finalNode->getDepth() != 0) {
        output << pow(Node::getTotalNumberOfNodes(), 1.f/(finalNode->getDepth())) << ",";
    } else { output << "0,"; }
    output << "\n";
    output.close();
}
