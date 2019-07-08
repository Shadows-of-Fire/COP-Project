#ifndef __AllPARTS_H
#define __ALLPARTS_H

#include "Part.h"
#include <vector>
#include <string>

class TextPart: public Part {
private:
	string text;
public:
	TextPart(string);
	virtual void print() const override;
	virtual void play() override;
};

class LinkPart: public Part {
private:
	string display;
	string target;
public:
	LinkPart(string, string);
	virtual void print() const override;
	virtual void play() override;
};

class GotoPart: public Part {
private:
	string target;
public:
	GotoPart(string);
	virtual void print() const override;
	virtual void play() override;
};

class IfPart: public Part {
protected:
	string variable;
	bool value;
public:
	IfPart(string, bool, part_t);
	IfPart(string, bool);
	virtual void print() const override;
	virtual void play() override;

};

class SetPart: public IfPart {
public:
	SetPart(string, bool);
	virtual void print() const override;
	virtual void play() override;
};

class ElseIfPart: public IfPart {
public:
	ElseIfPart(string, bool);
	virtual void print() const override;
	virtual void play() override;
};

class ElsePart: public Part {
public:
	ElsePart();
	virtual void print() const override;
	virtual void play() override;
};

class BlockPart: public Part {
private:
	vector<Part*> parts;
public:
	BlockPart();
	void addPart(Part*);
	virtual void print() const override;
	virtual void play() override;
};

#endif
