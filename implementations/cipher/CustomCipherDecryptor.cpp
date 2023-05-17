#include "../../classes/cipher/CustomCipher.h"

string CustomCipher::decrypt() {
    int keyLength = key.length();
    int textLength = text.length();
    int index = 0;

    vector<string> encryptedStringValues;
    encryptedStringValues.reserve(textLength);
    encryptedStringValues = calculateEncryptedStringValue(text, textLength);

    string decryptedText(textLength, ' ');

    try {
        for (string encryptedStringValue : encryptedStringValues) {
            string decryptedStringValue = stringValueDecryptor(encryptedStringValue);
            int decryptedIntValue = calculateDecryptedIntValue(decryptedStringValue);
            int originalIntValue = calculateOriginalIntValue(decryptedIntValue, key[index % keyLength], index);
            decryptedText[index] = static_cast<char>(originalIntValue);
            index++;
        }
    } catch (invalid_argument& e) {
        cerr << "Incorrect file data: " << e.what() << endl;
        throw invalid_argument("Error decrypting the file!");
    }
    text = decryptedText;
    return text;
}

vector<string> CustomCipher::calculateEncryptedStringValue(string text, int textLength) {
    vector<string> encryptedSequences;
    encryptedSequences.reserve(textLength);

    int i = 0;
    while(!text.empty()) {
        i++;
        int lengthOfSequence = text[0] - ':';
        string sequence = extractSequence(text, lengthOfSequence);
        string decompressedSequence = decompressSequence(sequence);
        encryptedSequences.push_back(decompressedSequence);
        text.erase(0, lengthOfSequence + 1);
    }

    return encryptedSequences;
}

string CustomCipher::extractSequence(string text, int lengthOfSequence) {
    string sequence = text.substr(1, lengthOfSequence);
    return sequence;
}

string CustomCipher::decompressSequence(const string sequence) {
    string decompressedSequence = "";
    int sequenceLength = sequence.length();
    int i = 0;

    while (i < sequenceLength) {
        if (sequence[i] >= ' ' && sequence[i] <= ')') {
            int symbolRepetitionCounter = (sequence[i] - ' ' - 1);
            i++;
            for (int j = 0; j < symbolRepetitionCounter; j++) {
                decompressedSequence += sequence[i];
            }
        } else {
            decompressedSequence += sequence[i];
            i++;
        }
    }

    return decompressedSequence;
}

string CustomCipher::stringValueDecryptor(string encryptedStringValue) {
    string decryptedStringValue = "";
    int intValue = 0;

    for (char c : encryptedStringValue) {
        intValue = intValue * 10 + (int)c - 'a';
    }

    while (intValue > 0) {
        char c = (char)(intValue % 10 + '0');
        decryptedStringValue = c + decryptedStringValue;
        intValue /= 10;
    }
    return decryptedStringValue;
}

int CustomCipher::calculateDecryptedIntValue(string decryptedStringValue){
    int decryptedStringValueLength = decryptedStringValue.length();
    int decryptedIntValue = 0;

    for (int i = 0; i < decryptedStringValueLength; i++) {
        if (isdigit(decryptedStringValue[i])) {
            decryptedIntValue = decryptedIntValue * 10 + (decryptedStringValue[i] - '0');
        } else {
            throw invalid_argument("Invalid data format!");
        }
    }
    return decryptedIntValue;
}

int CustomCipher::calculateOriginalIntValue(int decryptedIntValue, char keyChar, int index) {
    int keyLength = key.length();
    int originalIntValue = (decryptedIntValue - keyLength) / static_cast<int>(pow(static_cast<double>(keyChar), index % 3 + 1));
    return originalIntValue;
}
