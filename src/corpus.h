#ifndef CORPUS_H
#define CORPUS_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


class Corpus
{
    public:
        Corpus(char *filename);
        vector <string> list;
        
        void print();
        bool contains(char *word);
};

#endif
