//
// Created by morgan on 1/23/20.
//
#ifndef ASSIGNMENT_1_WORDTREEINTERFACE_H
#define ASSIGNMENT_1_WORDTREEINTERFACE_H

#pragma once

#include <string>

class WordTreeInterface
{
public:
    WordTreeInterface(){}

    virtual ~WordTreeInterface(){}

    virtual bool add(std::string word) = 0;

    //virtual int numWords(const WordTreeInterface &theTree) = 0;

};

#endif //ASSIGNMENT_1_WORDTREEINTERFACE_H