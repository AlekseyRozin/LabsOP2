#pragma once
#include <string>
#include <vector>
using namespace std;

struct Lesson {
	char subjectName[21];
	char startTime[6];
	char endTime[6];
};

vector<Lesson> getLessons();
string getName();
string getStartTime();
bool isTime(string time);
void validateLessons(Lesson lesson, string startTime, vector<Lesson>& lessons);
int getMinutes(string time);
string getEndingTime(string time);
void writeToBinaryFile(string fileName, vector<Lesson> lessons);
void getBinaryFileText(string fileName);