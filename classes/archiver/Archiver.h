#ifndef ARCHIVER_H
#define ARCHIVER_H

#include "iostream"
#include "string"
#include "unordered_map"
#include "queue"
#include "utils/Node.h"
#include "utils/Comparator.h"

using namespace std;

class Archiver {
public:
    Archiver() {}
    virtual string compress() = 0;
    virtual string decompress() = 0;
    virtual ~Archiver() {}
};

#endif
