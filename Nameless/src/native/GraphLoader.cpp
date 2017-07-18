//
// Created by CFWLoader on 7/17/17.
//

#include <native/GraphLoader.h>

using namespace nameless::native;

GraphLoader::GraphLoader(const std::string & filePath, const FileType & fileType) :
        file__(filePath, "r"),
        fileType__(fileType)
{}