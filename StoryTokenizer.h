#ifndef ___STORYTOKENIZER_H
#define ___STORYTOKENIZER_H 
#include "PassageTokenizer.h"

#include <string>
using namespace std;

class PassageToken
{
public:
    PassageToken(string);
    PassageToken();
    
    string getName() const {return name; }
    string getText() const {return text; }

private:
    string name;
    string text; 
};


class StoryTokenizer
{
public:
    StoryTokenizer(string);
    bool hasNextPassage();
    PassageToken nextPassage();
    
private: 
    string Story;
    string header;
    string tempPassage;
}; 


#endif
