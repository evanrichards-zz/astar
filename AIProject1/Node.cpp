//
//  Node.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include "Node.h"
int Node::staticId = 0;
MoveMap Node::moveMap = Node::initializeMoveMap();

Node::Node(int(*heuristic)(State), State state, Node* parentNode) {
    this->heuristic = heuristic;
    this->state = state;
    this->parentNode = parentNode;
    id = staticId;
    staticId++;
    
    successorStates = std::vector<State>();
    
    if(parentNode == nullptr){
        depth = 0;
    } else {
        depth = parentNode->depth + 1;
    }
    // Find zero location
    int zeroLocation;
    for (int i =  0; i < state.size(); i++) {
        if(state[i] == 0){
            zeroLocation = i;
            break;
        }
    }
    for (int i = 0; i < moveMap[zeroLocation].size(); i++) {
        successorStates.push_back(swap(state, zeroLocation, zeroLocation + moveMap[zeroLocation][i]));
    }
    
}

std::vector<State> Node::getSuccessors(){

    return successorStates;
}

int Node::getTotalNumberOfNodes(){
    return staticId;
}

int Node::getEvaluation(){
    return depth + heuristic(state);
}

MoveMap Node::initializeMoveMap(){

    MoveMap moveMap = MoveMap(9,std::vector<Directions>());
    
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
State Node::swap(State state, int index1, int index2){
    int temp = state[index1];
    state[index1] = state[index2];
    state[index2] = temp;
    return state;
}
