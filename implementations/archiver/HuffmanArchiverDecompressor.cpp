#include "../../classes/archiver/HuffmanArchiver.h"

string HuffmanArchiver::decompress() {

    try{
        validateFile();

        string archivedBinaryText = getArchivedBinaryText();
        unordered_map<char, string> symbolCodes = extractSymbolCodes();

        Node* root = buildHuffmanTree(symbolCodes);
        string decompressedText = decode(root, archivedBinaryText);

        return decompressedText;
    } catch(invalid_argument& e) {
        cerr << "Incorrect file structure: " << e.what() << endl;
        throw invalid_argument("Error decompressing the file!");
    }
}

void HuffmanArchiver::validateFile() {
    size_t newLinePosition = text.find('\n');
    if (newLinePosition == string::npos) {
        throw invalid_argument("No symbol mapping found!");
    }
}

string HuffmanArchiver::getArchivedBinaryText() {
    size_t newLinePosition = text.find('\n');
    string archivedBinaryText = text.substr(0, newLinePosition);
    return archivedBinaryText;
}

unordered_map<char, string> HuffmanArchiver::extractSymbolCodes() {
    size_t newLinePosition = text.find('\n');
    string::const_iterator symbolIterator = text.begin() + newLinePosition + 1;

    unordered_map<char, string> symbolCodes;
    while (*symbolIterator != '$') {
        char key = *symbolIterator;
        ++symbolIterator;

        if (*symbolIterator == '$' || *symbolIterator != '|') {
            throw invalid_argument("Damaged symbol mapping!");
        }
        ++symbolIterator;

        string value;
        while (*symbolIterator != '|' && *symbolIterator != '$') {
            value.push_back(*symbolIterator);
            ++symbolIterator;
        }

        symbolCodes.emplace(key, value);
        if (*symbolIterator == '$') {
            break;
        }

        if (*symbolIterator != '|') {
            throw invalid_argument("Damaged symbol mapping!");
        }
        ++symbolIterator;
    }

    return symbolCodes;
}

Node* HuffmanArchiver::buildHuffmanTree(const unordered_map<char, string>& symbolCodes) {
    Node* root = new Node('\0', 0, nullptr, nullptr);

    for (const auto& pair : symbolCodes) {
        Node* current = root;
        for (char c : pair.second) {
            if (c == '0') {
                if (current->left == nullptr) {
                    current->left = new Node('\0', 0, nullptr, nullptr);
                }
                current = current->left;
            } else if (c == '1') {
                if (current->right == nullptr) {
                    current->right = new Node('\0', 0, nullptr, nullptr);
                }
                current = current->right;
            }
        }
        current->data = pair.first;
    }

    return root;
}

string HuffmanArchiver::decode(Node* root, string& archivedBinaryText) {
    string decompressedText;

    int index = 0;
    while (index < static_cast<int>(archivedBinaryText.size())) {
        char decodedChar = decodeSymbol(root, archivedBinaryText, index);
        decompressedText += decodedChar;
    }

    return decompressedText;
}

char HuffmanArchiver::decodeSymbol(Node* root, string& archivedBinaryText, int& index) {
    if (root == nullptr) {
        return '\0';
    }

    if (root->left == nullptr && root->right == nullptr) {
        char val = root->data;
        archivedBinaryText.erase(0, index);
        index = 0;
        return val;
    }

    int encodedTextLength = archivedBinaryText.length();
    if (index < encodedTextLength) {
        if (archivedBinaryText[index] == '0'){
            index++;
            return decodeSymbol(root->left, archivedBinaryText, index);
        } else if (archivedBinaryText[index] == '1') {
            index++;
            return decodeSymbol(root->right, archivedBinaryText, index);
        }
    }

    return '\0';
}
