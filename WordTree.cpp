//
// Created by morgan on 1/23/20.
//
#include "WordTree.h"
#include <string>

WordTree::WordTree(string initialWord) {
    this->root = new WordNode(initialWord);
}

void WordTree::destructor(WordNode* currentNode) {
    if (currentNode == nullptr) {
        return;
    }
    destructor(currentNode->left);
    destructor(currentNode->right);
    delete currentNode;
}

WordTree::~WordTree() {
    destructor(this->root);
}