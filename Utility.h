#ifndef SRC_UTILITY_H_
#define SRC_UTILITY_H_

#include <string>

class LinkPart;
class Passage;

namespace std {

class Utility {
public:
	static void addLink(Passage*, LinkPart*);
	static void setPassage(string*);
	static void setVar(string, bool);
	static bool getVar(string);
};

}

#endif /* SRC_UTILITY_H_ */
