#ifndef TEXT_PROCESSOR_H
#define TEXT_PROCESSOR_H

#include "iostream"
#include "limits"
#include "unistd.h"
#include "../file/TextFile.h"
#include "../utils/Constants.h"
#include "../utils/Common.h"

using namespace std;

class TextProcessor{
public:
    TextProcessor();
    bool startPlainTextFileProcessing(TextFile* textFile);
    bool startEncryptedFileProcessing(TextFile* textFile);
    bool startArchivedFileProcessing(TextFile* textFile);
    ~TextProcessor();
};

#endif
