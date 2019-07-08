#ifndef SRC_PART_H_
#define SRC_PART_H_

using namespace std;

enum part_t {
	LINK, SET, GOTO, IF, ELSEIF, ELSE, BLOCK, TEXT
};

class Part {
protected:
	part_t type;
public:
	Part(part_t);
	virtual void print() const = 0;
	virtual void play() = 0;
	virtual ~Part();
};

#endif /* SRC_PART_H_ */
