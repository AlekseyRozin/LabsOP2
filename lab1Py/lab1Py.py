#импортируем файл с функциями
import funcs

#сохраняем названия файлов в перменные
inputFileName = "inputFile.txt"
outputFileName = "outputFile.txt"

#предлагаем пользователю ввести текст и записываем его в файл
lines = funcs.inputLines()
funcs.writeToFile(lines,inputFileName)

#сортируем текст входного файла по убыванию длины строк и добавляем длину строк в их начало
sortedLines = funcs.sortLines(lines)
resultLines = funcs.addLen(sortedLines)

#записываем отсортированый текст в файл
funcs.writeToFile(resultLines,outputFileName)

#выводим текст входного и выходного файлов
print("\nInput file text:")
funcs.getFileText(inputFileName)
print("\nOutput file text:")
funcs.getFileText(outputFileName)
