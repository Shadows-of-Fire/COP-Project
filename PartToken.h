#ifndef SRC_PARTTOKEN_H_
#define SRC_PARTTOKEN_H_

#include <string>

using namespace std;

enum part_t {
	LINK, SET, GOTO, IF, ELSEIF, ELSE, BLOCK, TEXT
};

class PartToken {
private:
	string data;
	part_t type;
public:
	PartToken(string, part_t);
	part_t getType() { return type; }
	string getText() { return data; }
};

#endif /* SRC_PARTTOKEN_H_ */
