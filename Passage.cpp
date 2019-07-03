#include "Passage.h"

Passage::Passage(string name) {
	this->name = name;
}

void Passage::addPart(Part* part) {
	this->parts.push_back(part);
}

void Passage::print() {

}

void Passage::printDebug() {

}

void Passage::play() {

}
