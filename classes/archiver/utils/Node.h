#ifndef NODE_H
#define NODE_H

class Node {
public:
    char data;
    int frequency;
    Node* left;
    Node* right;
    Node(char data, int frequency, Node* left, Node* right) {
        this->data = data;
        this->frequency = frequency;
        this->left = left;
        this->right = right;
    }
};

#endif
