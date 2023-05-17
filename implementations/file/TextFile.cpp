#include "../../classes/file/TextFile.h"

TextFile::TextFile() {}

TextFile::TextFile(string filePath) : File(filePath) {}

void TextFile::citire() {
    cout << "Enter the name of file(and extension): ";
    cin >> fileName;

    string fileNameAddress = filePath + fileName;
    ifstream fileLister(fileNameAddress);

    if (!fileLister.is_open()) {
        throw runtime_error("Error opening the file!\nMake sure that the file name and location are correct!");
    }

    string line;
    while (getline(fileLister, line)) {
        fileContent += line + "\n";
    }

    fileContent.pop_back();
    fileLister.close();
}

void TextFile::afisare() {
    string fileNameAddress = filePath + fileName;
    ifstream fileLister(fileNameAddress);

    if (!fileLister) {
        throw runtime_error("Error displaying the content!\nMake sure that the file was not renamed or deleted!");
    }

    string line;
    while (getline(fileLister, line)) {
        cout << line << endl;
    }
    fileLister.close();
}

string TextFile::criptare() {
    string key = "";
    cout << "Enter the secret key: ";
    cin >> key;
    cout << "Please don't forget the key and do not tell it to anybody since you will need it for decrypting the file!\n";

    cipher = new CustomCipher(fileContent, key);
    return cipher->encrypt();
}

string TextFile::decriptare() {
    string key = "";
    cout << "Enter the secret key: ";
    cin >> key;

    cipher = new CustomCipher(fileContent, key);
    return cipher->decrypt();
}

string TextFile::arhivare() {
    archiver = new HuffmanArchiver(fileContent);
    return archiver->compress();
}

string TextFile::dezarhivare() {
    archiver = new HuffmanArchiver(fileContent);
    return archiver->decompress();
}

void TextFile::salvare(string modifiedContent) {
    string fileNameAddress = filePath + fileName + fileEnding;
    ofstream fileListener(fileNameAddress);

    if (!fileListener.is_open()) {
        throw runtime_error("Error saving the file!");
    }

    fileListener << modifiedContent;
    fileListener.close();
}

string TextFile::getFileName(){
    return fileName;
}

void TextFile::setFileName(string fileName){
    this->fileName = fileName;
}

string TextFile::getFilePath(){
    return filePath;
}

void TextFile::setFilePath(string filePath){
    this->filePath = filePath;
}

string TextFile::getFileEnding(){
    return fileEnding;
}

void TextFile::setFileEnding(string fileEnding){
    this->fileEnding = fileEnding;
}

string TextFile::getFileContent(){
    return fileContent;
}

void TextFile::setFileContent(string fileContent){
    this->fileContent = fileContent;
}

TextFile::~TextFile() {
    delete cipher;
    delete archiver;
}
