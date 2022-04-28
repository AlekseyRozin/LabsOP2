#pragma once
#include "classes.h"
#include <string>
#include <vector>
using namespace std;

vector<string> getLines();
vector<Text> createTextsVector();
void addLines(vector<Text>& texts);
vector<string> getLongestLines(vector<Text> texts);
string getShortestLine(vector<string> lines);
void printTexts(vector<Text> texts);