#include "PartToken.h"

PartToken::PartToken(string data, part_t type) {
	this->data = data;
	this->type = type;
}

//TODO: After creating part classes, fix
Part* PartToken::asPart() {
	switch (type) {
	case LINK:
		break;
	case SET:
		break;
	case GOTO:
		break;
	case IF:
		break;
	case ELSEIF:
		break;
	case ELSE:
		break;
	case BLOCK:
		break;
	case TEXT:
		break;
	}
	return nullptr;
}
