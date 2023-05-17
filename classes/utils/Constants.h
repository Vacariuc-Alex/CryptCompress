#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "string"

using namespace std;

class Constants{
public:
    inline static const string FILE_PATH = "files/";
    inline static const string FILE_ENDING_ARCHIVED   = ".archived";
    inline static const string FILE_ENDING_UNARCHIVED = ".unarchived";
    inline static const string FILE_ENDING_ENCRYPTED  = ".encrypted";
    inline static const string FILE_ENDING_DECRYPTED  = ".decrypted";
};

#endif
