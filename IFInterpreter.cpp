#include "IFInterpreter.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "PartToken.h"
#include "PassageToken.h"
#include "PassageTokenizer.h"
#include "StoryTokenizer.h"

IFInterpreter* IFInterpreter::instance = nullptr;

IFInterpreter::IFInterpreter(string file) {
	ifstream stream(file);
	if (!stream.is_open()) {
		cout << "Failed to open " << file << ", the process will abort."
				<< endl;
	} else {
		string line, story;
		getline(stream, line);
		while (stream && line != "</html>") {
			story += line + '\n';
			getline(stream, line);
		}
		stream.close();
		StoryTokenizer tok(story);
		while (tok.hasNextPassage()) {
			PassageToken* psg = tok.nextPassage();
			PassageTokenizer psgTok(psg->getText());
			Passage* passage = new Passage(psg->getName());
			while (psgTok.hasNextPart()) {
				passage->addPart(psgTok.nextPart().asPart());
			}
			this->psgOrder.push_back(passage->getName());
			this->passages[passage->getName()] = passage;
		}
	}
	instance = this;
}

void IFInterpreter::print() {
	for (string& s : psgOrder) {
		passages.at(s)->print();
	}
}

void IFInterpreter::play() {
	active = passages.at(psgOrder.at(0));
	while (active != nullptr) {
		active->play();
	}
}

void IFInterpreter::setPassage(string* psg) {
	if (psg == nullptr)
		active = nullptr;
	else {
		active = passages.at(*psg);
	}
}

void IFInterpreter::setVar(string var, bool val) {
	this->vars[var] = val;
}

bool IFInterpreter::getVar(string var) {
	return this->vars.at(var);
}
