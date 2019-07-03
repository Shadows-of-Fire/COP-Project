#include "StoryTokenizer.h"

using namespace std;

const string NAME = "name=\"";
const string START = "<tw-passagedata";
const string END = "</tw-passagedata>";

StoryTokenizer::StoryTokenizer(string story) {
	this->story = story;
	this->readIdx = story.find("<body>", 0);
}

bool StoryTokenizer::hasNextPassage() {
	if (this->readIdx == string::npos)
		return false;
	return story.find("<tw-passagedata", readIdx) != string::npos;
}

PassageToken* StoryTokenizer::nextPassage() {
	size_t idx = story.find(START, readIdx);
	size_t nameIdx = story.find(NAME, idx) + NAME.size();
	size_t nameEnd = story.find("\"", nameIdx);
	string name = story.substr(nameIdx, nameEnd - nameIdx);
	size_t tagEnd = story.find(">", nameEnd) + 1;
	size_t closeTag = story.find(END, nameEnd);
	string text = story.substr(tagEnd, closeTag - tagEnd);
	this->readIdx = closeTag;
	return new PassageToken(name, text);
}
