#ifndef SRC_PASSAGETOKEN_H_
#define SRC_PASSAGETOKEN_H_

#include <string>

using namespace std;

class PassageToken {
private:
	string name;
	string text;
public:
	PassageToken(string, string);
	string getName() const {
		return name;
	}
	string getText() const {
		return text;
	}
};

#endif
