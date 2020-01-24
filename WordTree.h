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
        string word;
        int count;
        WordNode* left;
        WordNode* right;

        WordNode(string n, WordNode* l, WordNode* r): word(n), count(1), left(l), right(r) {}

        WordNode(string n): word(n), count(1), left(nullptr), right(nullptr) {}

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

    ~WordTree() override;

    bool add(string word);

    int numWords();



protected:
     void destructor(WordNode* currentNode);

     bool addHelper(WordNode* currentNode, string word);

     int numWordsHelper(const WordNode* currentNode);

     string createString(const WordNode* currentNode);

    string toLower(string word);
};

#endif //ASSIGNMENT_1_WORDTREE_H