//
// Created by morgan on 1/23/20.
//

#include "WordTree.h"
#include <string>

WordTree::WordTree(string initialWord) {
    this->root = new WordNode(initialWord);
}
