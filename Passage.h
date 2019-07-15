#ifndef SRC_PASSAGE_H_
#define SRC_PASSAGE_H_

#include <string>
#include <vector>

#include "AllParts.h"

using namespace std;

class Passage {
private:
	string name;
	vector<Part*> parts;
	vector<Part*> playParts;
	vector<LinkPart*> links;
	bool cont = true;
public:
	Passage(string);
	void addPart(Part*);
	string getName() {
		return name;
	}
	void print();
	void play();
	void stop() {
		cont = false;
	}
	void addLink(LinkPart*);
};

#endif /* SRC_PASSAGE_H_ */
