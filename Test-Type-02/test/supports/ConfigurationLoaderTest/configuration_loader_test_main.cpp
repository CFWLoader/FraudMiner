#include <iostream>

#include <supports/ConfigurationLoader.h>

using namespace std;
using namespace test_type02::supports;

int test01()
{
    ConfigurationLoader loader;

    string path = "../../../../conf/core";

    map<string, string> config = loader.convertConfigurationFromFile(path);

    for(auto pir : config)
    {
        cout << pir.first << ":" << pir.second << endl;
    }

    return 0;
}

int main()
{
    test01();

//    std::cout << "Hello, Socket!" << std::endl;

    return 0;
}