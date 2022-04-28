#include "classes.h"
#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Text::Text() {
	lines = getLines();
}

void Text::addNewLine(string line) {
	lines.push_back(line);
}

void Text::printText() {
	for (size_t i = 0; i < lines.size(); i++) {
		cout << lines[i] << endl;
	}
}

string Text::getLongestLine() {
	string longestLine = lines[0];
	for (size_t i = 1; i < lines.size(); i++) {
		if (lines[i].length() > longestLine.length()) longestLine = lines[i];
	}
	return longestLine;
}