#ifndef COMPARATOR_H
#define COMPARATOR_H

class Comparator {
public:
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

#endif
