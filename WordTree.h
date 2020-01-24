//
// Created by morgan on 1/23/20.
//
#ifndef ASSIGNMENT_1_WORDTREE_H
#define ASSIGNMENT_1_WORDTREE_H

#include "WordTreeInterface.h"
#include <string>

using namespace std;

class WordTree : public WordTreeInterface {
    struct WordNode {
        string name;
        int count;
        WordNode* left;
        WordNode* right;

        WordNode(string n, WordNode* l, WordNode* r): name(n), count(1), left(l), right(r) {}

        WordNode(string n): name(n), left(nullptr), right(nullptr) {}

        ~WordNode() {
            left = nullptr;
            right = nullptr;
            delete left;
            delete right;
        }

        void setLeft(WordNode* theNode) {
            left = theNode;
        }

        void setRight(WordNode* theNode) {
            right = theNode;
        }

        void increaseCount() {
            this->count++;
        }

    };

    WordNode* root;

public:
    WordTree(string initialWord);

    ~WordTree();

    bool add(WordNode toAd);

    int numWords();

protected:
     void destructor(WordNode* currentNode);

     int addHelper(const WordNode* toAd);

     int* numWordsHelper(const WordNode* currentNode);

     string createString(const WordNode* currentNode);
};

#endif //ASSIGNMENT_1_WORDTREE_H