//
// Created by CFWLoader on 7/5/17.
//
#include "../../include/NativeString.h"

using namespace nameless::native;

char* itoa(int num, int radix)
{}


String::String(const char* str) : str__(str)
{}

String::String(int int_num) : str__(itoa(int_num, 10))
{}