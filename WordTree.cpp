//
// Created by morgan on 1/23/20.
//
#include "WordTree.h"
#include <string>
#include<bits/stdc++.h>


WordTree::WordTree(string initialWord) {
    this->root = new WordNode(toLower(initialWord));
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

bool WordTree::addHelper(WordNode* currentNode, string word) {
    if (word == currentNode->word) {
        currentNode->increaseCount();
        return true;
    }
    if (word < currentNode->word) {
        if (currentNode->left == nullptr) {
            currentNode->left = new WordNode(word);
        } else {
        return addHelper(currentNode->left, word);
        }
    } else {
        if (currentNode->right == nullptr) {
            currentNode->right = new WordNode(word);
        } else {
            return addHelper(currentNode->right, word);
        }
    }
}

bool WordTree::add(string word) {
    return addHelper(this->root, toLower(word));
}

string WordTree::toLower(string word) {
    string temp = word;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    return temp;
}

int WordTree::numWordsHelper(const WordNode* currentNode) {
    if (currentNode == nullptr) {
        return 0;
    }
    int tempNum = 0;

    tempNum += currentNode->count;

    if (currentNode->left != nullptr) {
        tempNum += numWordsHelper(currentNode->left);
    }
    if (currentNode->right != nullptr) {
        tempNum += numWordsHelper(currentNode->right);
    }
    return tempNum;
}

int WordTree::numWords() {
    return numWordsHelper(this->root);
}