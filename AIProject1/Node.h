//
//  Node.h
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//
// TODO: Make heuristic static and set with setter

#ifndef __AIProject1__Node__
#define __AIProject1__Node__
#include <vector>
#include "MoveMapMaker.h"
typedef  std::vector<int> State;

class Node {
private:
    static int staticId;
    int heuristicNum;
    std::vector<State> successorStates;

    State swap(State state, int index1, int index2);
    int id;
    int depth;
    State state;
    Node* parentNode;
    std::vector<Node*> children;

public:
    Node(int heuristicNum, State state, Node* parentNode);
    ~Node();
    int getId(){return id;}
    int getDepth(){return depth;}
    State getState(){return state;}
    Node* getParentNode(){return parentNode;}
    std::vector<State> getSuccessors();
    int getEvaluation();
    static int getTotalNumberOfNodes();
    static void resetStaticId();
    void addChild(Node* child);
    
    // Override comparators for use in priorty queue.
    struct CompStr{
        bool operator()(Node* lhs, Node* rhs) const {
            if(lhs->getEvaluation()== rhs->getEvaluation()) {
                return lhs->id < rhs->id;
            }
            return lhs->getEvaluation() > rhs->getEvaluation();
        }
    };
};

#endif /* defined(__AIProject1__Node__) */
