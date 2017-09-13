//
// Created by CFWLoader on 9/13/17.
//

#ifndef TEST_TYPE_02_CONFIGURATIONLOADER_H
#define TEST_TYPE_02_CONFIGURATIONLOADER_H

#include <map>

namespace test_type02
{
    namespace supports
    {
        class ConfigurationLoader
        {
        public:

            static std::map<std::string, std::string> convertConfigurationFromFile(std::string);

        private:
        };
    }
}

#endif //TEST_TYPE_02_CONFIGURATIONLOADER_H
