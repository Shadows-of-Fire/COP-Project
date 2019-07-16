#include "PassageTokenizer.h"

#include <cstring>
#include <iostream>

#include "Part.h"

using namespace std;

PassageTokenizer::PassageTokenizer(string data) {
	this->data = data;
}

bool PassageTokenizer::hasNextPart() {
	unsigned int id = readIdx;
	if (id >= data.size())
		return false;
	char c = data.at(id);
	while (c == '\n' || c == '\r' || c == ' ') {
		c = data.at(id++);
		if (id >= data.size())
			return false;
	}
	return true;
}

PartToken PassageTokenizer::nextPart() {
	int read[] = { -1, -1 };
	walkData(read);
	PartToken* token = new PartToken(
			data.substr(readIdx, 1 + read[0] - readIdx), (part_t) read[1]);
	readIdx = (read[0] + 1);
	return *token;
}

bool isCmdStarter(string::size_type idx, string& str) {
	if (str.at(idx) == '(') {
		if (strcmp(str.substr(idx + 1, 5).c_str(), "go-to") == 0)
			return true;
		else if (strcmp(str.substr(idx + 1, 3).c_str(), "set") == 0)
			return true;
		else if (strcmp(str.substr(idx + 1, 2).c_str(), "if") == 0)
			return true;
		else if (strcmp(str.substr(idx + 1, 7).c_str(), "else-if") == 0)
			return true;
		else if (strcmp(str.substr(idx + 1, 4).c_str(), "else") == 0)
			return true;
	}
	return false;
}

/**
 * Returns two things: The part_t type of the next token found, and the readIdx of the end of this token for when it is consumed.
 * This method does not increment the readIdx of the tokenizer.
 */
void PassageTokenizer::walkData(int* ret) {
	char c = data.at(readIdx);
	while (c == '\n' || c == '\r' || c == ' ') {
		c = data.at(++readIdx);
	}
	if (c == '[') {
		if (readIdx + 2 < data.size() && data.at(readIdx + 1) == '['
				&& data.at(readIdx + 2) != '[') {
			ret[0] = data.find("]]", readIdx) + 1;
			ret[1] = LINK;
			return;
		} else {
			ret[1] = BLOCK;
			int brackets = 0;
			for (string::size_type i = readIdx + 1; i < data.size(); i++) {
				if (data.at(i) == '[') {
					brackets++;
				}
				if (data.at(i) == ']') {
					if (brackets == 0) {
						ret[0] = i;
						break;
					} else
						brackets--;
				}
			}
			return;
		}
	}
	if (c == '(') {
		string::size_type colon = data.find(':', readIdx);
		const char* cmd = data.substr(readIdx + 1, colon - readIdx - 1).c_str();
		bool fail = false;
		if (strcmp(cmd, "go-to") == 0)
			ret[1] = GOTO;
		else if (strcmp(cmd, "set") == 0)
			ret[1] = SET;
		else if (strcmp(cmd, "if") == 0)
			ret[1] = IF;
		else if (strcmp(cmd, "else-if") == 0)
			ret[1] = ELSEIF;
		else if (strcmp(cmd, "else") == 0)
			ret[1] = ELSE;
		else
			fail = true;
		if (!fail) {
			ret[0] = data.find(')', colon);
			return;
		}
	}
	ret[1] = TEXT;
	for (string::size_type i = readIdx; i < data.size(); i++) {
		if (data.at(i) == '[' || isCmdStarter(i, data)) {
			ret[0] = i - 1;
			return;
		}
	}
	ret[0] = data.size();
}
