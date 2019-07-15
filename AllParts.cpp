#include "AllParts.h"

#include <stddef.h>
#include <iostream>

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

void TextPart::play() {
	//TODO: Project Part 5
}

LinkPart::LinkPart(string display, string target) :
		Part(LINK) {
	this->display = display;
	this->target = target;
}

void LinkPart::print() const {
	cout << "Link:  display=" << display << ", target=" << target << endl;
}

void LinkPart::play() {
	//TODO: Project Part 5
	Passages.at(target)->play;
}

GotoPart::GotoPart(string target) :
		Part(GOTO) {
	this->target = target;
}

void GotoPart::print() const {
	cout << "Goto:  target=" << target << endl;
}

void GotoPart::play() {
	//TODO: Project Part 5
	passages.at(target)->play;
}

IfPart::IfPart(string variable, bool value, part_t type) :
		Part(type) {
	this->variable = variable;
	this->value = value;
}

IfPart::IfPart(string variable, bool value) :
		Part(IF) {
	this->variable = variable;
	this->value = value;
}

void IfPart::print() const {
	cout << "If:  var=" << variable << ", value=";
	pBool(value);
}

void IfPart::play() {
	//TODO: Project Part 5
	
}

SetPart::SetPart(string variable, bool value) :
		IfPart(variable, value, SET) {
}

void SetPart::print() const {
	cout << "Set:  var=" << variable << ", value=";
	pBool(value);
}

void SetPart::play() {
	//TODO: Project Part 5
	var.at(variable) = value;
}

ElseIfPart::ElseIfPart(string variable, bool value) :
		IfPart(variable, value, ELSEIF) {
}

void ElseIfPart::print() const {
	cout << "Else-if:  var=" << variable << ", value= ";
	pBool(value);
}

void ElseIfPart::play() {
	//TODO: Project Part 5
}

ElsePart::ElsePart() :
		Part(ELSE) {
}

void ElsePart::print() const {
	cout << "Else" << endl;
}

void ElsePart::play() {
	//TODO: Project Part 5
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

void BlockPart::play() {
	//TODO: Project Part 5
}
