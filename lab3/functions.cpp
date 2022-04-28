#include "functions.h"
#include "classes.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<string> getLines() {
    vector<string> lines;
    cout << "\nEnter yout text (press CTRL + X to end input):\n";

    string line;
    int endCode = 24;

    while (int(line[0]) != endCode) {
        getline(cin, line);
        lines.push_back(line);
    }
    lines.pop_back();

    return lines;
};

vector<Text> createTextsVector() {
    int count;
    vector<Text> texts;
    cout << "Enter how many Text objects you want to create: "; cin >> count;
    cin.ignore();
    for (size_t i = 0; i < count; i++) {
        texts.push_back(Text());
    }
    return texts;
}

void addLines(vector<Text>& texts) {
    string ans;
    cout << "Do you want to add new line (Y/N)? ";
    cin >> ans;
    while (ans != "N" && ans != "n") {
        while (ans != "Y" && ans != "y") {
            cout << "Wrong, enter 'Y' or 'N': ";
            cin >> ans;
        }
        int index;
        cout << "Enter number of the text to which you want to add line: "; cin >> index;
        while (index < 1 || index > texts.size()) {
            cin.ignore();
            cout << "Incorrect number, try one more time: "; cin >> index;
        }
        string line;
        cin.ignore();
        cout << "\nEnter your line: "; getline(cin, line);
        texts[index - 1].addNewLine(line);
        cout << "\nYour line was added!\n";
        cout << "Do you want to add new line (Y/N)? ";
        cin >> ans;
    }

}

vector<string> getLongestLines(vector<Text> texts) {
    vector<string> lines;
    for (size_t i = 0; i < texts.size(); i++) {
        string longestLine = texts[i].getLongestLine();
        lines.push_back(longestLine);
    }
    return lines;
}

string getShortestLine(vector<string> lines) {
    string shortestLine = lines[0];
    for (size_t i = 1; i < lines.size(); i++) {
        if (lines[i].length() < shortestLine.length()) shortestLine = lines[i];
    }
    return shortestLine;
}

void printTexts(vector<Text> texts) {
    for (size_t i = 0; i < texts.size(); i++) {
        cout << "\nText number " << i + 1 << ":\n";
        texts[i].printText();
    }
}