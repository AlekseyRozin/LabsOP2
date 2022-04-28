# импортируем файл с функциями
import funcs
# сохраняем имя файла в переменную
inputFileName = "inputTextPy.txt"

# создаем список классов и переобразовываем его в список строк
lessons = funcs.getLessons()

# записываем строки в файл
funcs.writeToFile(inputFileName,lessons)

# читаем текст из файла и выводим его в консоль
print('\nInput file text:')
funcs.getFileText(inputFileName)