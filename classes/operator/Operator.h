#ifndef OPERATOR_H
#define OPERATOR_H

#include "iostream"
#include "limits"
#include "unistd.h"
#include "../file/TextFile.h"
#include "../processor/TextProcessor.h"
#include "../utils/Constants.h"

using namespace std;

class Operator {
private:
    TextFile* textFile;
    TextProcessor* textProcessor;
public:
    Operator();
    void welcomeMessage();
    void mainMenuDisplay();
    void startTextFileProcessing();
    ~Operator();
};

#endif
