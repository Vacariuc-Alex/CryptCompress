#include "../../classes/cipher/CustomCipher.h"

string CustomCipher::encrypt() {
    int keyLength = key.length();
    int textLength = text.length();
    string encryptedText = "";

    for (int i = 0; i < textLength; i++) {
        int encryptedIntValue = calculateEncryptedIntValue(text[i], key[i % keyLength], keyLength, i);
        string encryptedStringValue = calculateEncryptedStringValue(encryptedIntValue);
        encryptedText += encryptedStringValue;
    }

    text = encryptedText;
    return text;
}

int CustomCipher::calculateEncryptedIntValue(char textChar, char keyChar, int keyLength, int index) {
    int encryptedIntValue = static_cast<int>(textChar) * static_cast<int>(pow(static_cast<double>(keyChar), index % 3 + 1)) + keyLength;
    return encryptedIntValue;
}

string CustomCipher::calculateEncryptedStringValue(int encryptedIntValue) {
    int numberOfDigits = 0;
    int reversedValue = 0;

    try {
        countDigitsAndReverseValue(encryptedIntValue, numberOfDigits, reversedValue);
    } catch(invalid_argument& e) {
        cerr << "Incorrect file data: " << e.what() << endl;
        throw invalid_argument("Error encrypting the file!");
    }

    string encryptedStringValue = constructEncryptedStringValue(numberOfDigits, reversedValue);
    string compressedString = compressString(encryptedStringValue);

    return compressedString;
}

void CustomCipher::countDigitsAndReverseValue(int value, int& numberOfDigits, int& reversedValue) {
    while (value > 0) {
        reversedValue = reversedValue * 10 + value % 10;
        value /= 10;
        numberOfDigits++;
    }

    if(numberOfDigits == 0) {
        throw invalid_argument("File contains non UTF-008 characters!");
    }
}

string CustomCipher::constructEncryptedStringValue(int numberOfDigits, int reversedValue) {
    string encryptedStringValue(numberOfDigits + 1, ' ');
    encryptedStringValue[0] = numberOfDigits + ':';

    for (int i = 1; i <= numberOfDigits; i++) {
        encryptedStringValue[i] = (reversedValue % 10) + 'a';
        reversedValue /= 10;
    }

    return encryptedStringValue;
}

string CustomCipher::compressString(const string encryptedStringValue) {
    string encryptedSequences = "";
    int symbolRepetitionCounter = 1;
    int encryptedStringValueLength = encryptedStringValue.length();

    for (int i = 1; i < encryptedStringValueLength; i++) {
        if (encryptedStringValue[i] == encryptedStringValue[i - 1]) {
            symbolRepetitionCounter++;
        } else {
            if (symbolRepetitionCounter > 1) {
                encryptedSequences += static_cast<char>(symbolRepetitionCounter) + ' ';
            }
            encryptedSequences += encryptedStringValue[i - 1];
            symbolRepetitionCounter = 1;
        }
    }

    if (symbolRepetitionCounter > 1) {
        encryptedSequences += static_cast<char>(symbolRepetitionCounter) + ' ';
    }

    encryptedSequences += encryptedStringValue[encryptedStringValueLength - 1];
    encryptedSequences[0] = encryptedSequences.length() + ':' - 1;

    return encryptedSequences;
}
