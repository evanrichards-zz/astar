//
//  Node.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include "Node.h"
int Node::staticId = 0;

Node::Node(int heuristicNum, State state, Node* parentNode) {
    this->heuristicNum = heuristicNum;
    this->state = state;
    this->parentNode = parentNode;
    id = staticId;
    staticId++;
    
    successorStates = std::vector<State>();
    
    if(parentNode == NULL){
        depth = 0;
    } else {
        depth = parentNode->depth + 1;
    }
    // Find zero location
    int zeroLocation = 0;
    for (int i =  0; i < state.size(); i++) {
        if(state[i] == 0){
            zeroLocation = i;
            break;
        }
    }
    MoveMap moveMap = MoveMapMaker::getMoveMap();
    for (int i = 0; i < moveMap[zeroLocation].size(); i++) {
        successorStates.push_back(swap(state, zeroLocation, zeroLocation + moveMap[zeroLocation][i]));
    }
    children = std::vector<Node*>();
    
}

Node::~Node(){
    if(!children.empty()){
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
}

std::vector<State> Node::getSuccessors(){
    return successorStates;
}

int Node::getTotalNumberOfNodes(){
    return staticId;
}

int Node::getEvaluation(){
    return depth + heuristicNum;
}

State Node::swap(State state, int index1, int index2){
    int temp = state[index1];
    state[index1] = state[index2];
    state[index2] = temp;
    return state;
}

void Node::resetStaticId(){
    staticId = 0;
}

void Node::addChild(Node* child){
    children.push_back(child);
}