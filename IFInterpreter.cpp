#include "IFInterpreter.h"

#include <fstream>
#include <iostream>
#include <utility>

#include "PartToken.h"
#include "PassageToken.h"
#include "PassageTokenizer.h"
#include "StoryTokenizer.h"

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
		StoryTokenizer tok(story);
		while (tok.hasNextPassage()) {
			PassageToken* psg = tok.nextPassage();
			PassageTokenizer psgTok(psg->getText());
			Passage* passage = new Passage(psg->getName());
			if (this->curPassage == nullptr) {
				this->curPassage = passage;
			}
			while (psgTok.hasNextPart()) {
				passage->addPart(psgTok.nextPart().asPart());
			}
			this->passages.emplace(passage->getName(), passage);
		}
		stream.close();
	}
}

void IFInterpreter::print() {

}

void IFInterpreter::printDebug() {
	//Unknown if necessary.
}

void IFInterpreter::play() {
	//TODO: Project Part 5
}