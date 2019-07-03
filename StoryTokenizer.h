#ifndef SRC_STORYTOKENIZER_H_
#define SRC_STORYTOKENIZER_H_

#include <cstddef>
#include <string>
#include "PassageToken.h"
#include "PassageTokenizer.h"
#include "PartToken.h"

using namespace std;

class StoryTokenizer {
private:
	string story;
	size_t readIdx = 0;
public:
	StoryTokenizer(string);
	bool hasNextPassage();
	PassageToken* nextPassage();
};

#endif
