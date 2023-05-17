#ifndef CUSTOM_CIPHER_H
#define CUSTOM_CIPHER_H

#include "Cipher.h"

class CustomCipher : public Cipher {
private:
    string text;
    string key;

    int calculateEncryptedIntValue(char textChar, char keyChar, int keyLength, int index);
    string calculateEncryptedStringValue(int encryptedIntValue);
    void countDigitsAndReverseValue(int value, int& numberOfDigits, int& reversedValue);
    string constructEncryptedStringValue(int numberOfDigits, int reversedValue);
    string compressString(const string encryptedStringValue);

    vector<string> calculateEncryptedStringValue(string text, int textLength);
    string extractSequence(string text, int lengthOfSequence);
    string decompressSequence(const string sequence);
    string stringValueDecryptor(string encryptedStringValue);
    int calculateDecryptedIntValue(string decryptedStringValue);
    int calculateOriginalIntValue(int decryptedIntValue, char keyChar, int index);

public:
    CustomCipher() {};
    CustomCipher(string text, string key) : text(text), key(key) {};

    string encrypt() override;
    string decrypt() override;

    ~CustomCipher() {};
};

#endif
