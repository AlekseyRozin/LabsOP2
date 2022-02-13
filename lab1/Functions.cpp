#include "Header.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

string getText() {
    cout << "Enter yout text (press CTRL + X to save file):\n";

    string text, line;
    int endCode = 24;

    while (int(line[0]) != endCode) {
        getline(cin, line);
        text += line + '\n';
    }

    text = text.substr(0, text.size() - 3);
    return text;
}

void writeToFile(string fileName, string text) {
    ofstream writeFile(fileName);
    writeFile << text;
    writeFile.close();
}

vector<string> getLines(string text) {
    vector<string> lines;
    size_t pos = 0;
    int prevPos = 0;
    while (pos <= text.length()) {
        if (text[pos] == '\n' || pos == text.length()) {
            string line = text.substr(prevPos, pos - prevPos);
            lines.push_back(line);
            prevPos = pos + 1;
        }
        pos++;
    }
    return lines;
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

string generateOutputText(vector<string> lines) {
    string text = "";
    for (size_t i = 0; i < lines.size(); i++) {
        string len = to_string(lines[i].size());
        string newLine = len + " " + lines[i];
        text += newLine;
        if (i != lines.size() - 1) {
            text += "\n";
        }
    }
    return text;
}