//
// Created by CFWLoader on 7/17/17.
//
#include <native/GraphLoader.h>
#include <native/NativeFile.h>
#include <iostream>

using namespace std;
using namespace nameless::native;

int generateGraph1(string filePath)
{
    NativeFile graphFile(filePath, "w+");

    graphFile.writeLine("1 2");
    graphFile.writeLine("1 3");
    graphFile.writeLine("1 4");
    graphFile.writeLine("2 4");

    return 0;
}

int constructorTest1()
{
    GraphLoader loader("./test.txt", GraphLoader::EDGE_LIST);

    return 0;
}


int main(int argc, char* argv[])
{
    generateGraph1("./test.txt");
    constructorTest1();
}