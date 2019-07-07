#include "AllParts.h"
#include <iostream>


TextPart::TextPart(string C) : Part(TEXT)
{
    Text = C;
}

void TextPart::print() const
{
 cout << "\"" << Text << "\"" << endl;   
}

void TextPart::play() 
{
    //todo.
}




LinkPart::LinkPart(string dis, string trgt) :Part(LINK)
{
    display = dis;
    target = trgt;
}

void LinkPart::print() const
{
    cout << "Link: \t display= " << display << ", target: " << target << endl;
}

void LinkPart::play() 
{
    //todo.
}




GotoPart::GotoPart(string trgt) : Part(GOTO)
{
    target = target;
}

void GotoPart::print() const
{
    cout << "go-to: \t target= " << target << endl;
}

void GotoPart::play() 
{
    //todo.
}




SetPart::SetPart(string variable, bool Val) : IfPart(variable, Val)
{
    type = SET;
}

void SetPart::print() const
{
    cout << "Set: \t var= " << var << ", value= " << value << endl;

}

void SetPart::play() 
{
    //todo.
}




IfPart::IfPart(string Variable, bool Val) : Part(IF)
{
    var = Variable;
    value = Val;
}

void IfPart::print() const
{
    cout << "If: \t Var= " << var << ", Value= " << value << endl;
}

void IfPart::play() 
{
    //todo.
}




ElseifPart::ElseifPart(string Variable, bool Val) : IfPart(Variable, Val)
{
    type = ELSEIF;
}

void ElseifPart::print() const
{
    cout << "Else-if: \t Var= " << var << ", value= " << value << endl;
}

//void ElseifPart::play() 
//{
    //todo.
//}



ElsePart::ElsePart(type_t C) : Part(C)
{

}

void ElsePart::print() const
{
    cout << "ELSE" << endl;
}

//void ElsePart::play() 
//{
    //todo.
//}




BlockPart::BlockPart() : Part(BLOCK)
{

}

void BlockPart::addPart(Part& part)
{
    Part* C= &part;
    parts.push_back(C);
}

void BlockPart::print() const
{
    cout << "START BLOCK" << endl;
    for (int i=0; i < parts.size(); i++)
        cout << parts[i] << endl;
    cout << "END BLOCK" << endl;
}

void BlockPart::play() 
{
    //todo.
}
