//
// Created by CFWLoader on 7/8/17.
//
#include <native/NativeFile.h>

#include <iostream>

using namespace std;
using namespace nameless::native;

int testConstructor1()
{

    NativeFile file("./constructorTest1.txt", "w");

    cout << "Hello!" << endl;

    return 0;

}

int testWrite1()
{

    NativeFile file("./writeTest1.txt", "w");

    auto size = file.write("123456");

    size += file.write("ABCDEF");

    cout << "Writed:" << size << "byte." << endl;

    return 0;

}

int testWrite2()
{

    NativeFile file("./writeTest2.txt", "w");

    auto size = file.write("123456");

    size += file.write("\n");

    size += file.write("ABCDEF");

    cout << "Writed:" << size << "byte." << endl;

    return 0;

}

int testWriteLine1()
{

    NativeFile file("./writeLineTest1.txt", "w");

    auto size = file.writeLine("123456");

    size += file.writeLine("ABCDEF");

    cout << "Writed:" << size << "byte." << endl;

    return 0;

}

int testReadLine1()
{

    NativeFile file("./readLineTest1.txt", "w+");

    auto size = file.writeLine("123456");

    size += file.writeLine("ABCDEF");

    size += file.writeLine("A1B2X3");

    file.close();

    NativeFile readerFile("./readLineTest1.txt", "r");

    auto count = 0;

    while(!readerFile.eof())
    {
        auto str = readerFile.readLine();

        cout << str << endl;

        ++count;

    }

    cout << count << endl;

    return 0;

}

int main()
{

    // writeTest2();

    // writeLineTest1();

    testReadLine1();

}