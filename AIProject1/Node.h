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

typedef  std::vector<int> State;
class Node {
private:
    static int staticId;
public:
    Node(int pathCost, int depth, State state, Node* parentNode) {
        this->pathCost = pathCost;
        this->depth = depth;
        this->state = state;
        this->parentNode = parentNode;
        id = staticId;
        staticId++;
    }
    int id;
    int pathCost;
    int depth;
    State state;
    Node* parentNode;
    
};

#endif /* defined(__AIProject1__Node__) */
