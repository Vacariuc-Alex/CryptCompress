#ifndef CIPHER_H
#define CIPHER_H

#include "iostream"
#include "math.h"
#include "vector"
#include "string"

using namespace std;

class Cipher {
public:
    Cipher() {};

    virtual string encrypt() = 0;
    virtual string decrypt() = 0;

    virtual ~Cipher() {};
};

#endif
