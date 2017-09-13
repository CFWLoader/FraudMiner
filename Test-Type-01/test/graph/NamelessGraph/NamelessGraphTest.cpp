//
// Created by CFWLoader on 7/18/17.
//
#include <graph/NamelessGraph.h>
#include <iostream>

using namespace std;
using namespace nameless::graph;

int testEdgeConstructor1()
{
    Edge<int, float> testEdge(1, 2, 2.3, 4.5);

    cout << testEdge.srcNode__ << "  " << testEdge.destNode__ << "  " << testEdge.srcWeight__ << "  " << testEdge.weight__ << endl;

    return 0;
}

int testUpdateAdjacency1()
{
    AdjacencyVertex<int, float> vertex(0, 1);

    vertex.addAdjacency(1, 1);
    vertex.addAdjacency(2, 3);
    vertex.addAdjacency(3, 4);

    for(auto item : vertex.neighbors)
    {
        cout << item.first << " " << item.second << endl;
    }

    vertex.updateAdjacency(2, 10);

    for(vector<pair<int, float>>::iterator iter = vertex.neighbors.begin();
            iter != vertex.neighbors.end();
            ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

int testRemoveAdjacency1()
{
    AdjacencyVertex<int, float> vertex(0, 1);

    vertex.addAdjacency(1, 1);
    vertex.addAdjacency(2, 3);
    vertex.addAdjacency(3, 4);

    for(auto item : vertex.neighbors)
    {
        cout << item.first << " " << item.second << endl;
    }

    vertex.removeAdjacency(2);

    for(vector<pair<int, float>>::iterator iter = vertex.neighbors.begin();
        iter != vertex.neighbors.end();
        ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
    }

    return 0;
}

int testFindAdjacency1()
{
    AdjacencyVertex<int, float> vertex(0, 1);

    vertex.addAdjacency(1, 1);
    vertex.addAdjacency(2, 3);
    vertex.addAdjacency(3, 4);

//    for(auto item : vertex.neighbors)
//    {
//        cout << item.first << " " << item.second << endl;
//    }
//
//    vertex.removeAdjacency(2);
//
//    for(vector<pair<int, float>>::iterator iter = vertex.neighbors.begin();
//        iter != vertex.neighbors.end();
//        ++iter)
//    {
//        cout << iter->first << " " << iter->second << endl;
//    }
    pair<int, float> target = vertex.findAdjacency(3);

    cout << target.first << " " << target.second << endl;

    pair<int, float> target2 = vertex.findAdjacency(4);

    cout << target2.first << " " << target2.second << endl;

    return 0;
}

int main(int argc, char* argv[])
{
    // edgeConstructorTest1();

    // updateAdjacencyTest();

    // removeAdjacencyTest();

    testFindAdjacency1();
}