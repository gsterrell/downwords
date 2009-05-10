#include "corpus.h"

Corpus::Corpus(char *filename){    
    ifstream file(filename);
    string line;
    
    if (file.is_open())
    {
        while(! file.eof() )
        {
            getline (file, line);
            list.push_back(line);
        }
        file.close();
    }
}

void 
Corpus::print(){
    for (int i=0; i<list.size(); i++){
        cout << list[i] << endl;
    }
}

bool 
Corpus::contains(char *word){
    for (int i=0; i<list.size(); i++){
        if (! list[i].compare(word))
            return true;
    }
    return false;
}
