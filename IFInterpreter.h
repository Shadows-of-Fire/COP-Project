#ifndef SRC_IFINTERPRETER_H_
#define SRC_IFINTERPRETER_H_

#include <string>
#include <unordered_map>

#include "Passage.h"

using namespace std;

class IFInterpreter {
private:
	unordered_map<string, bool> vars;
	unordered_map<string, Passage*> passages;
	Passage* curPassage;
public:
	IFInterpreter(string);
	void print();
	void printDebug();
	void play();
};



#endif /* SRC_IFINTERPRETER_H_ */
