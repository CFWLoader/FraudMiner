//
// Created by CFWLoader on 7/5/17.
//
#include <cstdio>
#include <string>
#include <cstring>

#include <NativeFile.h>

using namespace nameless::native;

using std::string;

NativeFile::NativeFile(const string& filePath, const string& mode) :
        fp__(fopen(filePath.c_str(), mode.c_str()))
{}

NativeFile::NativeFile(const std::string & filePath, const char* mode) :
        fp__(fopen(filePath.c_str(), mode))
{}

bool NativeFile::eof() const
{

    return (bool) feof(fp__);

}

bool NativeFile::close()
{
    if(fp__ == NULL)
    {
        return true;
    }

    fclose(fp__);

    fp__ = NULL;

    return true;
}

size_t NativeFile::write(const std::string & data)
{

    //fprintf(fp__, "%s", data.c_str());
    return fwrite(data.c_str(), sizeof(char), data.length(), fp__);

}

size_t NativeFile::write(const char * data)
{

    return fwrite(data, sizeof(char), strlen(data), fp__);

}

size_t NativeFile::writeLine(const std::string& data)
{

    size_t written = fwrite(data.c_str(), sizeof(char), data.length(), fp__);

    fprintf(fp__, "\n");

    written += 1;

    return written;

}

size_t NativeFile::writeLine(const char * data)
{

    size_t written = fwrite(data, sizeof(char), strlen(data), fp__);

    fprintf(fp__, "\n");

    written += 1;

    return written;
}

string NativeFile::readLine()
{
    if(this->eof())
    {
        return "";
    }

    memset(buf__, 0, MAX_BUF_SIZE__);

    fgets(buf__,  MAX_BUF_SIZE__, fp__);

    size_t idx = strlen(buf__);

    // printf("idx:%d\n", idx);

    if(idx > 0){buf__[idx - 1] = '\0';}

    return string(buf__);

}

NativeFile::~NativeFile()
{
    this->close();
}
