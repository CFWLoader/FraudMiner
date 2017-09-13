//
// Created by CFWLoader on 9/13/17.
//
#include <syslog.h>

#include <fstream>

#include <supports/ConfigurationLoader.h>

using namespace test_type02::supports;

std::map<std::string, std::string> ConfigurationLoader::convertConfigurationFromFile(std::string filePath)
{
    std::map<std::string, std::string> config;

    std::ifstream in(filePath);

    if(!in.is_open())
    {
        syslog(LOG_ERR, "The file doesn't exist.");

        return config;
    }

    std::string str;

    while(!in.eof())
    {
        in >> str;

        std::string::iterator iter;

        for(iter = str.begin();
                iter != str.end() and *iter != '=';
                ++iter);

        config[std::string(str.begin(), iter)] = std::string(iter + 1, str.end());

    }

    in.close();

    return config;
}