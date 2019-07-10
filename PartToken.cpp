#include "PartToken.h"

#include <stddef.h>
#include <iostream>

#include "AllParts.h"
#include "PassageTokenizer.h"

PartToken::PartToken(string data, part_t type) {
	this->data = data;
	this->type = type;
}

Part* PartToken::asPart() {
	switch (type) {
	case LINK: {
		size_t gt = data.find("-&gt;", 0);
		if (gt == string::npos) {
			string psg = data.substr(2, data.length() - 4);
			return new LinkPart(psg, psg);
		}
		string display = data.substr(2, data.length() - (gt - 1));
		string psg = data.substr(gt + 5, gt + 5 - (data.length() - 2));
		return new LinkPart(display, psg);
	}
	case SET: {
		int start = data.find("$", 0);
		int end = data.find(" ", start);
		string val = data.substr(data.find(" to ", 0) + 4, 4);
		return new SetPart(data.substr(start, end - start), val == "true");
	}
	case GOTO: {
		int start = data.find("&quot;", 0) + 6;
		int end = data.find("&quot;", start);
		return new GotoPart(data.substr(start, end - start));
	}
	case IF: {
		int start = data.find("$", 0);
		int end = data.find(" ", start);
		string val = data.substr(data.find(" is ", 0) + 4, 4);
		return new IfPart(data.substr(start, end - start), val == "true");
	}
	case ELSEIF: {
		int start = data.find("$", 0);
		int end = data.find(" ", start);
		string val = data.substr(data.find(" is ", 0) + 4, 4);
		return new ElseIfPart(data.substr(start, end - start), val == "true");
	}
	case ELSE:
		return new ElsePart();
	case BLOCK: {
		BlockPart* part = new BlockPart();
		PassageTokenizer tok(data.substr(1, data.length() - 2));
		while (tok.hasNextPart()) {
			part->addPart(tok.nextPart().asPart());
		}
		return part;
	}
	default:
		return new TextPart(data);
	}
}
