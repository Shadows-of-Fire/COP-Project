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
public:
	PassageTokenizer(string);
	bool hasNextPart();
	PartToken nextPart();
	void walkData(int*);
};

#endif /* SRC_PASSAGETOKENIZER_H_ */
