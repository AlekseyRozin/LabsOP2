#include "Header.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<string> getLines() {
    vector<string> lines;
    cout << "Enter yout text (press CTRL + X to save file):\n";

    string line;
    int endCode = 24;

    while (int(line[0]) != endCode) {
        getline(cin, line);
        lines.push_back(line);
    }
    lines.pop_back();

    return lines;
}

void writeToFile(string fileName, vector<string> lines) {
    ofstream writeFile(fileName);
    for (size_t i = 0; i < lines.size(); i++) {
        writeFile << lines[i];
        if (i != lines.size() - 1) {
            writeFile << "\n";
        }
    }
    writeFile.close();
}


void sortLines(vector<string>& lines) {
    for (size_t i = 0; i < lines.size() - 1; i++) {
        for (size_t j = 0; j < lines.size() - 1; j++) {
            if (lines[j].length() <= lines[j + 1].length()) {
                string temp = lines[j];
                lines[j] = lines[j + 1];
                lines[j + 1] = temp;
            }
        }
    }
}

void addLen(vector<string>& lines) {
    for (size_t i = 0; i < lines.size(); i++) {
        lines[i] = to_string(lines[i].size()) + " " + lines[i];
    }
}

void getFileText(string fileName) {
    ifstream file(fileName);
    string temp;
    while (getline(file, temp)) {
        cout << temp << endl;
    }
    file.close();
}