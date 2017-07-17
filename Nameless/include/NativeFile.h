//
// Created by CFWLoader on 7/5/17.
//

#ifndef NAMELESS_NATIVEFILE_H
#define NAMELESS_NATIVEFILE_H

#include <stdio.h>
#include <string>

namespace nameless::native
{

    class NativeFile
    {
    public:

        const static size_t MAX_BUF_SIZE__ = 4096;

        NativeFile(const std::string&, const std::string&);

        NativeFile(const std::string&, const char*);

        bool eof() const;

        bool close();

        size_t write(const std::string&);

        size_t write(const char*);

        size_t writeLine(const std::string&);

        size_t writeLine(const char*);

        std::string readLine();

        virtual ~NativeFile();

    private:

        FILE* fp__;

        char buf__[MAX_BUF_SIZE__];

    };
}

#endif //NAMELESS_NATIVEFILE_H
