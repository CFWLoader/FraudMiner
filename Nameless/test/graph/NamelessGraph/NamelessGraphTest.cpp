//
// Created by CFWLoader on 7/18/17.
//
#include <graph/NamelessGraph.h>
#include <iostream>

using namespace std;
using namespace nameless::graph;

int edgeConstructorTest1()
{
    Edge<int, float> testEdge(1, 2, 2.3, 4.5);

    cout << testEdge.srcNode__ << "  " << testEdge.destNode__ << "  " << testEdge.srcWeight__ << "  " << testEdge.weight__ << endl;

    return 0;
}

int main(int argc, char* argv[])
{
    edgeConstructorTest1();
}