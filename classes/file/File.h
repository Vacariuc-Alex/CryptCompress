#ifndef FILE_H
#define FILE_H

#include "iostream"
#include "fstream"
#include "string"
#include "limits"
#include "unistd.h"

using namespace std;

class File {
protected:
    string fileName;
    string filePath;
    string fileEnding;
    string fileContent;
public:
    File() {}
    File(string filePath) : filePath(filePath) {}

    virtual void citire() = 0;
    virtual void afisare() = 0;
    virtual void salvare(string modifiedContent) = 0;

    virtual ~File() {}
};

#endif
