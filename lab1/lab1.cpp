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
    string inputText = getText();
    writeToFile(inputFileName, inputText);

    //разбиваем текст на строки, сортируем их по длинне и добавляем длину строк в их начало
    vector<string> lines = getLines(inputText);
    sortLines(lines);
    string newText = generateOutputText(lines);

    //записываем новый текст в файл
    writeToFile(outputFileName, newText);

    //выводим текст входного и выходного файлов
    cout << "\nInput file text:\n" << inputText;
    cout << "\n\nOutput file text:\n" << newText;
}