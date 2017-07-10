//
// Created by CFWLoader on 7/8/17.
//
#include <NativeFile.h>

#include <iostream>

using namespace std;
using namespace nameless::native;

int main()
{

    NativeFile file("./local.txt", "w");

    cout << "Hello!" << endl;

    return 0;
}