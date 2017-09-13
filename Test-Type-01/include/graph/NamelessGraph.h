//
// Created by CFWLoader on 7/17/17.
//

#ifndef NAMELESS_NAMELESSGRAPH_H
#define NAMELESS_NAMELESSGRAPH_H

#include <vector>
#include <algorithm>

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

        bool removeAdjacency(ID_TYPE neighborId)
        {
            neighbors.erase(std::remove_if(neighbors.begin(), neighbors.end(),
                           [neighborId](std::pair<ID_TYPE, WEIGHT_TYPE> pair__){return pair__.first == neighborId;}),
                            neighbors.end());

            return true;
        }

        bool updateAdjacency(ID_TYPE neighborId, WEIGHT_TYPE new_cost = WEIGHT_TYPE())
        {
            typename std::vector<std::pair<ID_TYPE, WEIGHT_TYPE>>::iterator target =
                    std::find_if(neighbors.begin(), neighbors.end(), [neighborId](std::pair<ID_TYPE, WEIGHT_TYPE> pair__){return pair__.first == neighborId;});

            target->second = new_cost;

            return true;
        }

        std::pair<ID_TYPE, WEIGHT_TYPE> findAdjacency(ID_TYPE neighborId)
        {
            typename std::vector<std::pair<ID_TYPE, WEIGHT_TYPE>>::iterator target =
                    std::find_if(neighbors.begin(), neighbors.end(), [neighborId](std::pair<ID_TYPE, WEIGHT_TYPE> pair__){return pair__.first == neighborId;});

            return *target;
        };

        ID_TYPE srcNode__;

        WEIGHT_TYPE srcWeight__;

        std::vector<std::pair<ID_TYPE, WEIGHT_TYPE>> neighbors;

    };
}

#endif //NAMELESS_NAMELESSGRAPH_H
