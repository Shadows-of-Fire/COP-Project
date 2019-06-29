#include "PassageTokenizer.h"
PassageTokenizer::PassageTokenizer(string C)
{
    Passage = C;
}
PartToken PassageTokenizer::nextPart()
{
    
    char type;                          
    int ch=0;                       //keeps track of the index for the last character read.
    type = Passage[0];              
    if(type == '(')
    {
        ch = Passage.find_first_of(')')+1;
        Part = Passage.substr(0, ch);
    }
    else if (type == '[')
    {
        
        int Brackets =1;                    
        int i=1;
        for(i; i < Passage.length() && Brackets !=0; i++)
        {
            if(Passage[i]== '[')                        //keeps track of the number of opening brackets.
                Brackets++;
            else if(Passage[i]== ']')                   //keeps track of the closing brakcets.
                Brackets--;            
            
        }
        ch = i;
        Part = Passage.substr(0, ch);
    }
    else 
    {
        if(Passage.find('(') != string::npos)                //checks that there're no opening parenthesis.
        {
            ch = Passage.find_first_of('(');
            Part = Passage.substr(0, ch);
        }
        else if (Passage.find('[') != string::npos)          //checks that there're no opening brackets.
        {  
            ch = Passage.find_first_of('[');
            Part = Passage.substr(0, ch);
        }
        else                                                //if there're no opening brackets it'll read until it reaches the end of the string.
        {
            Part = Passage;
            ch = Passage.length();
        }
    }
    string temp = Passage.substr(ch);
    Passage= temp;                                     //temp value to change the Passage string.
    PartToken TokenPart(Part);
    return TokenPart;
}

bool PassageTokenizer::hasNextPart()
{
    if (Passage.empty())
        return false;
    else 
    return true;
}

PartToken::PartToken(string C)
{
    string Initial_Char = C.substr(0, 2);                      //tracks the first 2 characters from the string
    text = C;
    if (text.at(0) == '[')                                      
    {
        if (text.at(1) == '[' && C.at(2)!= '[')
            TokenType = LINK;
        else TokenType = BLOCK;
    }
    else if (Initial_Char == "(g") 
        TokenType= GOTO;
    else if (Initial_Char == "(s")
        TokenType = SET;
    else if (Initial_Char == "(i")
        TokenType = IF;
    else if (Initial_Char == "(e")
    {
        if (text.find("else-if") != string::npos)                  //checks for string "else-if".
            TokenType = ELSEIF;
        else TokenType = ELSE;
    }
    else TokenType = TEXT;
}

