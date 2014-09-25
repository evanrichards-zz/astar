//
//  Node.h
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#ifndef __AIProject1__Node__
#define __AIProject1__Node__
#include <vector>
enum Directions {UP = -3, RIGHT = 1, DOWN = 3, LEFT = -1};

typedef  std::vector<int> State;
typedef std::vector<std::vector<Directions> > MoveMap;

class Node {
private:
    static int staticId;
    std::vector<State> successorStates;
    static MoveMap initializeMoveMap();
    static MoveMap moveMap;
    State swap(State state, int index1, int index2);
    int(*heuristic)(State);
    int id;
    int depth;
    State state;
    Node* parentNode;


public:
    Node(int(*heuristic)(State), State state, Node* parentNode);
    
    int getId(){return id;}
    int getDepth(){return depth;}
    State getState(){return state;}
    Node* getParentNode(){return parentNode;}
    std::vector<State> getSuccessors();
    int getEvaluation();
    static int getTotalNumberOfNodes();
    
    // Override comparators for use in priorty queue.
    struct CompStr{
        bool operator()(Node* lhs, Node* rhs) const {
            if(lhs->getEvaluation()== rhs->getEvaluation()) {
                return lhs->id < rhs->id;
            }
            return lhs->getEvaluation() == rhs->getEvaluation();
        }
    };
    
};

#endif /* defined(__AIProject1__Node__) */
