#ifndef SRC_PASSAGETOKENIZER_H_
#define SRC_PASSAGETOKENIZER_H_

#include <string>
#include "PartToken.h"

using namespace std;

class PassageTokenizer {
private:
	string data;
	size_t readIdx = 0;
	bool ready = true;
	void walkData(int*);
public:
	PassageTokenizer(string);
	bool hasNextPart();
	PartToken nextPart();
};

#endif /* SRC_PASSAGETOKENIZER_H_ */
