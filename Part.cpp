#include "Part.h"

#include <utility>

#include "AllParts.h"

Part::Part(part_t type) {
	this->type = type;
}

Part::~Part() {
}

void Part::makeIfControllers(vector<Part*>& parts,
		vector<Part*>& playParts) {
	for (unsigned int i = 0; i < parts.size(); i++) {
		Part* p = parts.at(i);
		if (p->getType() == IF) {
			vector<pair<IfPart*, BlockPart*>> ctrl;
			IfPart* _if = (IfPart*) p;
			BlockPart* ifChild = (BlockPart*) parts.at(++i);
			ctrl.push_back(*new pair<IfPart*, BlockPart*>(_if, ifChild));
			Part* next = parts.at(i + 1);
			while (next->getType() == ELSEIF || next->getType() == ELSE) {
				BlockPart* child = (BlockPart*) parts.at(i + 2);
				i += 2;
				ctrl.push_back(*new pair<IfPart*, BlockPart*>((IfPart*) next, child));
				if (i + 1 == parts.size())
					break;
				next = parts.at(i + 1);
			}
			playParts.push_back(new IfControllerPart(ctrl));
		} else
			playParts.push_back(p);
	}
}
