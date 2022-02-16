#include "Header.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    //сохраняем названия файлов в переменные
    string inputFileName = "inputText.txt";
    string outputFileName = "outputText.txt";

    //предлагаем пользователю ввести текст и записываем его в файл
    vector<string> lines = getLines();
    writeToFile(inputFileName, lines);

    //сортируем вектор строк и добавляем к каждой строке ее длину в ее начало
    sortLines(lines);
    addLen(lines);

    //записываем новый текст в файл
    writeToFile(outputFileName, lines);

    //выводим текст входного и выходного файлов
    cout << "\nInput file text:\n";
    getFileText(inputFileName);
    cout << "\nOutput file text:\n";
    getFileText(outputFileName);
}