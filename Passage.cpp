#include "Passage.h"

#include <iostream>

#include "IFInterpreter.h"
#include "Part.h"

Passage::Passage(string name) {
	this->name = name;
}

void Passage::addPart(Part* part) {
	this->parts.push_back(part);
}

void Passage::print() {
	cout << "Passage " << name << ':' << endl;
	for (Part* p : parts) {
		p->print();
	}
}

void Passage::play() {
	Part::makeIfControllers(parts, playParts);
	for (Part* p : playParts) {
		p->play(this);
		if (p->getType() == GOTO)
			return;
	}
	if (!links.empty()) {
		cout << "Select a link from the list." << endl;
		for (unsigned int i = 0; i < links.size(); i++) {
			cout << i + 1 << ". " << links.at(i)->getDisplay() << endl;
		}
		unsigned int link;
		cin >> link;
		while (cin.fail() || link > links.size() || link < 1) {
			cin.ignore(10000, '\n');
			cin.clear();
			cin >> link;
		}
		IFInterpreter::instance->setPassage(links.at(link - 1)->getTarget());
	} else {
		IFInterpreter::instance->setPassage(nullptr);
	}
}

void Passage::addLink(LinkPart* part) {
	this->links.push_back(part);
}
