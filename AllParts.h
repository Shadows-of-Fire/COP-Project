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
	virtual void play(Passage*) override;
};

class LinkPart: public Part {
private:
	string display;
	string target;
public:
	LinkPart(string, string);
	virtual void print() const override;
	virtual void play(Passage*) override;
	string getDisplay() {
		return display;
	}
	string* getTarget(){
		return &target;
	}
};

class GotoPart: public Part {
private:
	string target;
public:
	GotoPart(string);
	virtual void print() const override;
	virtual void play(Passage*) override;
};

class IfPart: public Part {
protected:
	string variable;
	bool value;
public:
	IfPart(string, bool, part_t);
	IfPart(string, bool);
	virtual void print() const override;
	virtual void play(Passage*) override {};
	virtual bool isTrue();
};

class ElseIfPart: public IfPart {
public:
	ElseIfPart(string, bool);
	virtual void print() const override;
	virtual void play(Passage*) override {};
};

class ElsePart: public IfPart {
public:
	ElsePart();
	virtual void print() const override;
	virtual void play(Passage*) override {};
	virtual bool isTrue() override { return true; }
};

class SetPart: public IfPart {
public:
	SetPart(string, bool);
	virtual void print() const override;
	virtual void play(Passage*) override;
};

class BlockPart: public Part {
private:
	vector<Part*> parts;
	vector<Part*> playParts;
public:
	BlockPart();
	void addPart(Part*);
	virtual void print() const override;
	virtual void play(Passage*) override;
};

class IfControllerPart: public Part {
protected:
	vector<pair<IfPart*, BlockPart*>> parts;
public:
	IfControllerPart(vector<pair<IfPart*, BlockPart*>>);
	virtual void print() const override {};
	virtual void play(Passage*) override;
};

#endif
