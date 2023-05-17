#include "../../classes/archiver/HuffmanArchiver.h"

string HuffmanArchiver::compress() {
    unordered_map<char, int> frequencies;
    unordered_map<char, string> symbolsAndCodes;
    priority_queue<Node*, vector<Node*>, Comparator> huffmanBinaryTreeElements;
    string compressedText = "";

    calculateFrequencies(frequencies);
    arrangeElementsByFrequencies(frequencies, huffmanBinaryTreeElements);
    buildHuffmanTree(huffmanBinaryTreeElements);
    encodeHuffmanTree(huffmanBinaryTreeElements.top(), "", symbolsAndCodes);
    buildCompressedText(symbolsAndCodes, compressedText);

    return compressedText;
}

void HuffmanArchiver::calculateFrequencies(unordered_map<char, int>& frequencies) {
    for (char c : text) {
        frequencies[c]++;
    }
}

void HuffmanArchiver::arrangeElementsByFrequencies(const unordered_map<char, int>& frequencies, priority_queue<Node*, vector<Node*>, Comparator>& huffmanBinaryTreeElements) {
    for (auto pair : frequencies) {
        huffmanBinaryTreeElements.push(new Node(pair.first, pair.second, nullptr, nullptr));
    }
}

void HuffmanArchiver::buildHuffmanTree(priority_queue<Node*, vector<Node*>, Comparator>& huffmanBinaryTreeElements) {
    while (huffmanBinaryTreeElements.size() != 1) {
        Node* left = huffmanBinaryTreeElements.top();
        huffmanBinaryTreeElements.pop();

        Node* right = huffmanBinaryTreeElements.top();
        huffmanBinaryTreeElements.pop();

        int sum = left->frequency + right->frequency;
        huffmanBinaryTreeElements.push(new Node('\0', sum, left, right));
    }
}

void HuffmanArchiver::encodeHuffmanTree(Node* root, string optimizedCode, unordered_map<char, string>& symbolsAndCodes) {
    if (root == nullptr) {
        return;
    }

    if (!root->left && !root->right) {
        symbolsAndCodes[root->data] = optimizedCode;
    }

    encodeHuffmanTree(root->left, optimizedCode + "0", symbolsAndCodes);
    encodeHuffmanTree(root->right, optimizedCode + "1", symbolsAndCodes);
}

void HuffmanArchiver::buildCompressedText(unordered_map<char, string>& symbolsAndCodes, string& compressedText) {
    for (char c : text) {
        compressedText += symbolsAndCodes[c];
    }

    compressedText += '\n';
    for (auto pair : symbolsAndCodes) {
        compressedText.push_back(pair.first);
        compressedText.push_back('|');

        compressedText.append(pair.second);
        compressedText.push_back('|');
    }

    compressedText += '$';
}
