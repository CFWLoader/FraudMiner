//
// Created by CFWLoader on 7/5/17.
//

#ifndef NAMELESS_NATIVESTRING_H
#define NAMELESS_NATIVESTRING_H

namespace nameless::native
{
    class String
    {
    public:

        String(const char*);

        String(int);

        String(unsigned int);

        String(long);

        String(unsigned long);

        String(float);

        String(double);


    private:

        const char* str__;

    };
}

#endif //NAMELESS_NATIVESTRING_H
