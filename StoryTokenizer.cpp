#include "StoryTokenizer.h"
#include <string>

StoryTokenizer::StoryTokenizer(string C)
{
    int Startofbody = C.find("<tw-passagedata ");   //
    Story = C.substr(Startofbody);
    header= "</tw-passagedata>";
}

bool StoryTokenizer::hasNextPassage()
{
    bool HasNextPassage;
    if(Story.find(header) != string::npos)
        return true;
    else 
        return false;
}

PassageToken StoryTokenizer::nextPassage()
{
    header= "</tw-passagedata>";
    int endofpassage = Story.find(header);
    
    tempPassage = Story.substr(0, endofpassage);
    
    string tempStory = Story.substr(endofpassage+16);
    Story = tempStory;
    PassageToken Passage(tempPassage);

    return Passage;
}

PassageToken::PassageToken(string tempPassage)
{
   int Ind_StartPassage = tempPassage.find("\">");
   int Index_Name = tempPassage.find("name");
   int Index_endofName = tempPassage.find("tags=");
   name = tempPassage.substr(Index_Name+6, Index_endofName - Index_Name-8);
   text = tempPassage.substr(Ind_StartPassage+2);
}

PassageToken::PassageToken()
{
    name = '\0';
    text = '\0';
}