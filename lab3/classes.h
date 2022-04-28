#pragma once
#include <string>
#include <vector>
using namespace std;

class Text {
private:
	vector<string> lines;
public:
	Text();
	void addNewLine(string line);
	void printText();
	string getLongestLine();
};