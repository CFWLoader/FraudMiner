//
// Created by CFWLoader on 6/9/17.
//

#ifndef P1_GRAPH_BASE_GRAPH_H
#define P1_GRAPH_BASE_GRAPH_H

#include <vector>
#include <stdint.h>

class Empty{};

template<typename ContentType = Empty>
class Node
{
public:

    Node(uint64_t node_num_, ContentType* content_ = nullptr);

    bool addNeighbor(Node<ContentType>*);

private:

    uint64_t node_num;

    const ContentType* content;

    std::vector<Node<ContentType>*> neighbors;

};

class Graph
{

};

template<typename ContentType>
Node<ContentType>::Node(uint64_t node_num_,  ContentType* content_) :
        node_num(node_num_), content(content_), neighbors(0)
{}


template<typename ContentType>
bool Node<ContentType>::addNeighbor(Node *node)
{
    neighbors.push_back(node);

    return true;
}


#endif //P1_GRAPH_BASE_GRAPH_H
