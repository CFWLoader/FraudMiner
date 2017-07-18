//
// Created by CFWLoader on 7/17/17.
//

#ifndef NAMELESS_NAMELESSGRAPH_H
#define NAMELESS_NAMELESSGRAPH_H

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
    };
}

#endif //NAMELESS_NAMELESSGRAPH_H
