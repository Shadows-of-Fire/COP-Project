#include "Passage.h"

#include <iostream>

Passage::Passage(string name) {
	this->name = name;
}

void Passage::addPart(Part* part) {
	this->parts.push_back(part);
}

void Passage::print() {
	cout << "Passage " << name << ':' << endl;
	for(Part* p : parts){
		p->print();
	}
}

void Passage::printDebug() {

}

void Passage::play() {
	//TODO: Project part 5
}
