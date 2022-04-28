#include "Header.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //сохраняем названия файлов в переменные 
    string inputFileName = "inputText.txt";

    //предлагаем пользователю ввести расписание
    vector<Lesson> lessons = getLessons();

    //записываем строки в файл
    writeToBinaryFile(inputFileName, lessons);

    //читаем из файла и выводим его содержимое в консоль
    cout << "\nInput file text:\n";
    getBinaryFileText(inputFileName);
}