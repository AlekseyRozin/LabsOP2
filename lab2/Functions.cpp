#include "Header.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

vector<Lesson> getLessons() {
    int count;
    vector<Lesson> lessons;

    cout << "Enter how many lessons do you wanna add: "; cin >> count;
    cin.ignore();
    cout << "\n";

    for (int i = 0; i < count; i++) {
        Lesson mySubject;
        strcpy_s(mySubject.subjectName, getName().c_str());
        string startTime = getStartTime();
        strcpy_s(mySubject.startTime, startTime.c_str());
        size_t currentSize = lessons.size();
        validateLessons(mySubject, startTime, lessons);
        if (lessons.size() == currentSize) i--;
    }
    return lessons;
}

string getName() {
    string name;
    cout << "Enter name of the subject: "; cin >> name;
    while (name.length() > 20 || name.length() < 1) {
        cout << "Incorrect length of name, try one more time: "; cin >> name;
    }
    return name;
}

bool isTime(string time) {
    if (time.length() > 5 || time.length() < 5) return false;
    else if (time[2] != ':') return false;
    else if (!isdigit(time[0]) || !isdigit(time[1]) || !isdigit(time[3]) || !isdigit(time[4])) return false;
    else if (stoi(time.substr(0, 2)) > 23 || stoi(time.substr(0, 2)) < 0) return false;
    else if (stoi(time.substr(3, 2)) > 59 || stoi(time.substr(3, 2)) < 0) return false;
    return true;
}

string getStartTime() {
    string startTime;
    cout << "Enter starting time of the lesson in this format [HH:MM]: "; cin >> startTime;
    while (!isTime(startTime)) {
        cout << "Incorrect time format, try one more time: "; cin >> startTime;
    }
    return startTime;
}

void validateLessons(Lesson lesson, string startTime, vector<Lesson>& lessons) {
    if (lessons.size() == 0) {
        string ending = getEndingTime(startTime);
        strcpy_s(lesson.endTime, ending.c_str());
        lessons.push_back(lesson);
    }
    else {
        int currMinutes = getMinutes(lesson.startTime);
        int prevMinutes = getMinutes(lessons[lessons.size() - 1].endTime);
        int minutesDiff = currMinutes - prevMinutes;
        if (minutesDiff < 5 || minutesDiff > 45) {
            cout << "Turn cannot be more than 45 minutes and less than 5 minutes!\n";
        }
        else {
            string ending = getEndingTime(startTime);
            strcpy_s(lesson.endTime, ending.c_str());
            lessons.push_back(lesson);
        }
    }

}

int getMinutes(string time) {
    size_t semicolonIndex = time.find(':');
    int hours = stoi(time.substr(0, semicolonIndex));
    int minutes = stoi(time.substr(semicolonIndex + 1));
    return hours * 60 + minutes;
}

string getEndingTime(string time) {
    int totalMinutesStart = getMinutes(time);
    int totalMinutesEnd = totalMinutesStart + 105;
    int hoursEnd = totalMinutesEnd / 60;
    int minutesEnd = totalMinutesEnd % 60;
    string newTime = to_string(hoursEnd) + ":";
    newTime += minutesEnd == 0 ? "00" : to_string(minutesEnd);
    return newTime;
}




void writeToBinaryFile(string fileName, vector<Lesson> lessons) {
    ofstream file;
    string ans;
    cout << "Do you want to rewrite information (Y/N)? ";
    cin >> ans;
    while (ans != "Y" && ans != "y" && ans != "N" && ans != "n") {
        cout << "Wrong, enter 'Y' or 'N': ";
        cin >> ans;
    }
    if (ans == "Y" or ans == "y") file.open(fileName, ios::binary);
    else file.open(fileName, ios::binary | ios::app);

    for (size_t i = 0; i < lessons.size(); i++)
    {
        file.write((char*)&lessons[i], sizeof(Lesson));
    }
    file.close();

}


void getBinaryFileText(string fileName) {
    Lesson subject{};
    ifstream file(fileName, ios::binary);
    while (file.read((char*)&subject, sizeof(Lesson))) {
        string name = subject.subjectName;
        string start = subject.startTime;
        string end = subject.endTime;
        cout << name + ", " + start + ", " + end << endl;
    }
    file.close();
}
