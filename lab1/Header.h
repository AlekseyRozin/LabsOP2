#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


string getText();
void writeToFile(string fileName, string text);
vector<string> getLines(string text);
void sortLines(vector<string>& lines);
string generateOutputText(vector<string> lines);