import keyboard

def inputFile(fileName):
    print("\nEnter yout text (press Shift + Enter to save file):")
    lines = ""
    myFile = open(fileName, "w")
    while not keyboard.is_pressed('shift'):
        line = input()
        lines += line + "\n"
    myFile.write(lines[:-1])
    myFile.close()


def getFileText(fileName):
    myFile = open(fileName)
    fileText = myFile.read()
    myFile.close()
    return fileText


def sortLines(text):
    lines = text.split("\n")
    for i in range(len(lines)-1):
        for j in range(len(lines) - 1):
            if len(lines[j]) <= len(lines[j+1]):
                lines[j], lines[j+1] = lines[j+1],lines[j]
    return "\n".join(lines)


def addLen(text):
    lines = text.split("\n")
    newLines = []
    for line in lines:
        newLine = str(len(line)) + " " + line
        newLines.append(newLine)
    newText = "\n".join(newLines)
    return newText


def createOutputFile(text,fileName):
    myFile = open(fileName, "w+")
    myFile.write(text)
    myFile.close()

