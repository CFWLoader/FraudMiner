//
// Created by CFWLoader on 7/17/17.
//

#ifndef NAMELESS_GRAPHLOADER_H
#define NAMELESS_GRAPHLOADER_H

#include <string>

#include <NativeFile.h>

namespace nameless::native
{
    class GraphLoader
    {
    public:

        enum FileType{EDGE_LIST, ADJACENCY_LIST};

        GraphLoader(const std::string&, const FileType&);

    private:

        NativeFile file__;

        FileType fileType__;

    };
}

#endif //NAMELESS_GRAPHLOADER_H
