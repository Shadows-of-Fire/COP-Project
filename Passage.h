#ifndef SRC_PASSAGE_H_
#define SRC_PASSAGE_H_

#include <string>
#include <vector>

#include "Part.h"

using namespace std;

class Passage {
private:
	string name;
	vector<Part*> parts;
public:
	Passage(string);
	void addPart(Part*);
	string getName() {
		return name;
	}
	void print();
	void play();
};

#endif /* SRC_PASSAGE_H_ */
