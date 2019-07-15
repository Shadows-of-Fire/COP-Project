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
	Passage* active = nullptr;
public:
	static IFInterpreter* instance;
	IFInterpreter(string);
	void print();
	void play();
	void setPassage(string*);
	void setVar(string, bool);
	bool getVar(string);
};

#endif /* SRC_IFINTERPRETER_H_ */
