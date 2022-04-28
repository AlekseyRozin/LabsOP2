#include "classes.h"
#include "functions.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    //создаем массив объектов класса текст 
    vector<Text> texts = createTextsVector();

    //предлагаем пользователю добавить строки
    addLines(texts);

    //выводим текста
    printTexts(texts);

    //сохраняем самые длинные строки в каждом тексте в массив
    vector<string> longestLines = getLongestLines(texts);

    //сохраняем самое короткую строку из самых длинных строк и выводим ее
    string shortestOfLongest = getShortestLine(longestLines);
    cout << "\nThe shortest line among longest lines in texts is:\n" << shortestOfLongest;
}