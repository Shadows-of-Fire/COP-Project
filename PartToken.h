#ifndef SRC_PARTTOKEN_H_
#define SRC_PARTTOKEN_H_

#include <string>
#include "Part.h"

using namespace std;

class PartToken {
private:
	string data;
	part_t type;
public:
	PartToken(string, part_t);
	part_t getType() { return type; }
	string getText() { return data; }
	Part* asPart();
};

#endif /* SRC_PARTTOKEN_H_ */
