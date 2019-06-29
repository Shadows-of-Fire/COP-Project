#include "PassageTokenizer.h"

#include <cstring>

using namespace std;

PassageTokenizer::PassageTokenizer(string data) {
	this->data = data;
}

bool PassageTokenizer::hasNextPart() {
	return ready;
}

PartToken PassageTokenizer::nextPart() {
	int read[] = { -1, -1 };
	walkData(read);
	PartToken token(data.substr(readIdx, 1 + read[0] - readIdx),
			(part_t) read[1]);
	readIdx = read[0] + 1;
	if (readIdx >= data.size())
		ready = false;
	return token;
}

/**
 * Returns two things: The part_t type of the next token found, and the readIdx of the end of this token for when it is consumed.
 * This method does not increment the readIdx of the tokenizer.
 */
void PassageTokenizer::walkData(int* ret) {
	char c = data[readIdx];
	if (c == '[') {
		if (data[readIdx + 1] == '[') {
			ret[0] = data.find("]]", readIdx) + 1;
			ret[1] = LINK;
			return;
		} else {
			ret[1] = BLOCK;
			int brackets = 0;
			for (size_t i = readIdx + 1; i < data.size(); i++) {
				if (data[i] == '[') {
					brackets++;
				}
				if (data[i] == ']') {
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
		int colon = data.find(':', readIdx);
		const char* cmd = data.substr(readIdx + 1, colon - readIdx - 1).c_str();
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
		ret[0] = data.find(')', colon);
		return;
	} else {
		ret[1] = TEXT;
		for (size_t i = readIdx; i < data.size() + 1; i++) {
			if (data[i] == '[' || data[i] == '(' || data[i] == '\0') {
				ret[0] = i - 1;
				break;
			}
		}
	}
}
