#импортируем файл с функциями
import funcs

#сохраняем названия файлов в перменные
inputFileName = "inputFile.txt"
outputFileName = "outputFile.txt"

#создаем входной файл и сохраняем его текст в переменную
funcs.inputFile(inputFileName)
inputFileText = funcs.getFileText(inputFileName)

#сортируем текст входного файла по убыванию длины строк и добавляем длину строк в их начало
sortedText = funcs.sortLines(inputFileText)
resultText = funcs.addLen(sortedText)

#создаем выходной файл и сохраняем его текст в переменную
funcs.createOutputFile(resultText,outputFileName)
outputFileText = funcs.getFileText(outputFileName)

#выводим текст входного и выходного файлов
print("\nText in the input file:\n",inputFileText)
print("\nText in the output file:\n",outputFileText)
