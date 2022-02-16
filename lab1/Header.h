#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


vector<string> getLines();
void writeToFile(string fileName, vector<string> lines);
void sortLines(vector<string>& lines);
void addLen(vector<string>& lines);
void getFileText(string fileName);