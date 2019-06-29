#ifndef __PASSAGETOKENIZER_H
#define __PASSAGETOKENIZER_H
#include <string>
using namespace std;

enum type_t {LINK, SET, GOTO, IF, ELSEIF, ELSE, BLOCK, TEXT};
class PartToken;

class PassageTokenizer
{
private:
    string Part, Passage;
public:
    PassageTokenizer(string);
    PartToken nextPart();
    bool hasNextPart();
}; 

class PartToken
{
private:
    type_t TokenType;
    string text;

public:
    PartToken(string);
    string getText() const {return text;}
    type_t getType() const {return TokenType;}
};

#endif