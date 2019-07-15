#include "AllParts.h"

#include <stddef.h>
#include <iostream>

#include "Utility.h"

static void pBool(bool b) {
	cout << (b ? "true" : "false") << endl;
}

TextPart::TextPart(string text) :
		Part(TEXT) {
	this->text = text;
}

void TextPart::print() const {
	cout << '"' << text << '"' << endl;
}

void TextPart::play(Passage* psg) {
	cout << text;
}

LinkPart::LinkPart(string display, string target) :
		Part(LINK) {
	this->display = display;
	this->target = target;
}

void LinkPart::print() const {
	cout << "Link:  display=" << display << ", target=" << target << endl;
}

void LinkPart::play(Passage* psg) {
	cout << display;
	Utility::addLink(psg, this);
}

GotoPart::GotoPart(string target) :
		Part(GOTO) {
	this->target = target;
}

void GotoPart::print() const {
	cout << "Goto:  target=" << target << endl;
}

void GotoPart::play(Passage* psg) {
	Utility::setPassage(&target);
}

IfPart::IfPart(string variable, bool value, part_t type) :
		Part(type) {
	this->variable = variable;
	this->value = value;
}

IfPart::IfPart(string variable, bool value) :
		IfPart(variable, value, IF) {
}

void IfPart::print() const {
	cout << "If:  var=" << variable << ", value=";
	pBool(value);
}

bool IfPart::isTrue() {
	return Utility::getVar(variable) == value;
}

ElseIfPart::ElseIfPart(string variable, bool value) :
		IfPart(variable, value, ELSEIF) {
}

void ElseIfPart::print() const {
	cout << "Else-if:  var=" << variable << ", value= ";
	pBool(value);
}

ElsePart::ElsePart() :
		IfPart("", false, ELSE) {
}

void ElsePart::print() const {
	cout << "Else" << endl;
}

SetPart::SetPart(string variable, bool value) :
		IfPart(variable, value, SET) {
}

void SetPart::print() const {
	cout << "Set:  var=" << variable << ", value=";
	pBool(value);
}

void SetPart::play(Passage* psg) {
	Utility::setVar(variable, value);
}

BlockPart::BlockPart() :
		Part(BLOCK) {
}

void BlockPart::addPart(Part* part) {
	parts.push_back(part);
}

void BlockPart::print() const {
	cout << "START BLOCK" << endl;
	for (size_t i = 0; i < parts.size(); i++)
		parts.at(i)->print();
	cout << "END BLOCK" << endl;
}

void BlockPart::play(Passage* psg) {
	Part::makeIfControllers(parts, playParts);
	for (Part* p : playParts) {
		p->play(psg);
		if (p->getType() == GOTO)
			return;
	}
}

IfControllerPart::IfControllerPart(vector<pair<IfPart*, BlockPart*>> parts) :
		Part(IF) {
	this->parts = parts;
}

void IfControllerPart::play(Passage* psg) {
	for (pair<IfPart*, BlockPart*>& part : parts) {
		if (part.first->isTrue()) {
			part.second->play(psg);
			return;
		}
	}
}
