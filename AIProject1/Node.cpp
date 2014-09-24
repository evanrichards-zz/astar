//
//  Node.cpp
//  AIProject1
//
//  Created by Evan Richards on 9/23/14.
//  Copyright (c) 2014 Evan Richards. All rights reserved.
//

#include "Node.h"
int Node::staticId = 0;

bool operator<(const Node& lhs, const Node& rhs){
    if(rhs.pathCost == lhs.pathCost){
        return rhs.id < lhs.id;
    }
    return rhs.pathCost < lhs.pathCost;
}

bool operator>(const Node& lhs, const Node& rhs){
    return rhs < lhs;
}

bool operator<=(const Node& lhs, const Node& rhs){
    return !(lhs>rhs);
}

bool operator>=(const Node& lhs, const Node& rhs){
    return !(lhs<rhs);
}

bool operator==(const Node& lhs, const Node& rhs){
    return lhs.id == rhs.id;
}

bool operator!=(const Node& lhs, const Node& rhs){
    return lhs.id != rhs.id;
}
