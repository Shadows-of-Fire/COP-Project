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
	vector<string> psgOrder;
public:
	IFInterpreter(string);
	void print();
	void play();
};



#endif /* SRC_IFINTERPRETER_H_ */
