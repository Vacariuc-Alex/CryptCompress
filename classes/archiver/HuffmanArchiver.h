#ifndef HUFFMAN_ARCHIVER_H
#define HUFFMAN_ARCHIVER_H

#include "Archiver.h"

class HuffmanArchiver : public Archiver {
private:
    Node* root;
    string text;

    void encode(Node* root, string optimizedCode, unordered_map<char, string> &symbolsAndCodes);
    void calculateFrequencies(unordered_map<char, int>& frequencies);
    void arrangeElementsByFrequencies(const unordered_map<char, int>& frequencies, priority_queue<Node*, vector<Node*>, Comparator>& huffmanBinaryTreeElements);
    void buildHuffmanTree(priority_queue<Node*, vector<Node*>, Comparator>& huffmanBinaryTreeElements);
    void encodeHuffmanTree(Node* root, string optimizedCode, unordered_map<char, string>& symbolsAndCodes);
    void buildCompressedText(unordered_map<char, string>& symbolsAndCodes, string& compressedText);

    char decode(Node* root, string& str, int& index);
    void validateFile();
    string getArchivedBinaryText();
    unordered_map<char, string> extractSymbolCodes();
    Node* buildHuffmanTree(const unordered_map<char, string>& symbolCodes);
    string decode(Node* root, string& archivedBinaryText);
    char decodeSymbol(Node* root, string& archivedBinaryText, int& index);

public:
    HuffmanArchiver() {};
    HuffmanArchiver(string text) : text(text) {};

    string compress() override;
    string decompress() override;

    ~HuffmanArchiver() {};
};

#endif
