//
// Created by CFWLoader on 7/5/17.
//
#include <cstdio>
#include <string>

#include "../../include/NativeFile.h"

using namespace nameless::native;

using std::string;

NativeFile::NativeFile(const string& filePath, const string& mode) :
        fp__(fopen(filePath.c_str(), mode.c_str()))
{}

NativeFile::~NativeFile()
{
    fclose(fp__);

    fp__ = NULL;
}
