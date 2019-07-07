#ifndef __AllPARTS_H
#define __ALLPARTS_H
#include "Part.h"
#include <vector>

class TextPart: public Part
{
private:
    string Text;
public:
    TextPart(string);
    virtual void print() const override;
    virtual void play() override;
};



class LinkPart : public Part
{
private:
    string display;
    string target;
public:
    LinkPart(string, string);
    virtual void print() const override;
    virtual void play() override;
};



class GotoPart : public Part
{
private:    
    string target;
public:
    GotoPart(string);
    virtual void print() const override;
    virtual void play() override;
};



class SetPart : public IfPart
{
public:
    SetPart(string, bool);
    virtual void print() const override;
    virtual void play() override;
};



class IfPart : public Part
{
protected:
    string var;
    bool value;
public: 
    IfPart(string, bool);
    virtual void print() const override;
    virtual void play() override;

};



class ElseifPart : public IfPart
{
public:
    ElseifPart(string, bool);
    virtual void print() const override;
   // virtual void play() override;
};



class ElsePart : public Part
{
public:
    ElsePart(type_t);
    virtual void print() const override;

};



class BlockPart : public Part
{
private:
    vector<Part*> parts;
public:
    BlockPart();
    void addPart(Part&);
    virtual void print() const override;
    virtual void play() override;
};


#endif