//
// Created by CFWLoader on 7/5/17.
//

#ifndef NAMELESS_NATIVEFILE_H
#define NAMELESS_NATIVEFILE_H

#include <stdio.h>

namespace nameless::native
{

    class NativeFile
    {
    public:

        NativeFile(const std::string&, const std::string&);

        virtual ~NativeFile();

    private:

        FILE* fp__;

    };
}

#endif //NAMELESS_NATIVEFILE_H
