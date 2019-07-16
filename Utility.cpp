#include "Utility.h"

#include <iostream>

#include "IFInterpreter.h"
#include "Passage.h"

namespace std {

void Utility::addLink(Passage* psg, LinkPart* link) {
	psg->addLink(link);
}

void Utility::setPassage(string* psg) {
	IFInterpreter::instance->setPassage(psg);
}

void Utility::setVar(string var, bool val) {
	IFInterpreter::instance->setVar(var, val);
}

bool Utility::getVar(string var) {
	return IFInterpreter::instance->getVar(var);
}

}
