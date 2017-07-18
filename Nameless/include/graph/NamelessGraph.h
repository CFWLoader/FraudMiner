//
// Created by CFWLoader on 7/17/17.
//

#ifndef NAMELESS_NAMELESSGRAPH_H
#define NAMELESS_NAMELESSGRAPH_H

#include <vector>

namespace nameless::graph
{
    template<typename ID_TYPE, typename WEIGHT_TYPE>
    class Edge
    {
    public:

        Edge(ID_TYPE src_node, ID_TYPE dest_node, WEIGHT_TYPE src_weight = WEIGHT_TYPE(), WEIGHT_TYPE weight = WEIGHT_TYPE()):
            srcNode__(src_node), destNode__(dest_node), srcWeight__(src_weight), weight__(weight)
        {}

        ID_TYPE srcNode__;

        ID_TYPE destNode__;

        WEIGHT_TYPE srcWeight__;

        WEIGHT_TYPE weight__;
    };

    template<typename ID_TYPE, typename WEIGHT_TYPE>
    class AdjacencyVertex
    {
    public:

        AdjacencyVertex(ID_TYPE srcNode, WEIGHT_TYPE srcWeight = WEIGHT_TYPE()) :
            srcNode__(srcNode),
            srcWeight__(srcWeight),
            neighbors()
        {}

        bool addAdjacency(ID_TYPE neighborId, WEIGHT_TYPE cost = WEIGHT_TYPE())
        {
            neighbors.push_back(std::pair<ID_TYPE, WEIGHT_TYPE>(neighborId, cost));

            return true;
        }

        ID_TYPE srcNode__;

        WEIGHT_TYPE srcWeight__;

        std::vector<std::pair<ID_TYPE, WEIGHT_TYPE>> neighbors;

    };
}

#endif //NAMELESS_NAMELESSGRAPH_H
