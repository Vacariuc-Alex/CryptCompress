#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include "File.h"
#include "../cipher/CustomCipher.h"
#include "../archiver/HuffmanArchiver.h"

class TextFile : public File {
private:
    Cipher* cipher;
    Archiver* archiver;
public:
    TextFile();
    TextFile(string filePath);

    void citire() override;
    void afisare() override;
    void salvare(string modifiedContent) override;

    string criptare();
    string decriptare();
    string arhivare();
    string dezarhivare();

    string getFileName();
    void setFileName(string fileName);
    string getFilePath();
    void setFilePath(string fileEnding);
    string getFileEnding();
    void setFileEnding(string fileEnding);
    string getFileContent();
    void setFileContent(string fileContent);

    ~TextFile();
};

#endif
