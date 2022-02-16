import keyboard

def inputLines():
    print("Enter yout text (press Shift + Enter to save file):")
    lines = []
    while not keyboard.is_pressed('shift'):
        line = input()
        lines.append(line)
    return lines


def writeToFile(lines,fileName):
    file = open(fileName, "w+")
    for i in range(0,len(lines)):
        file.write(lines[i])
        if not i == len(lines)-1:
            file.write("\n")
    file.close()


def sortLines(lines):
    for i in range(len(lines)-1):
        for j in range(len(lines) - 1):
            if len(lines[j]) <= len(lines[j+1]):
                lines[j], lines[j+1] = lines[j+1],lines[j]
    return lines


def addLen(lines):
    newLines = []
    for line in lines:
        newLine = str(len(line)) + " " + line
        newLines.append(newLine)
    return newLines


def getFileText(fileName):
    file = open(fileName, "r")
    while True:
        line = file.readline()
        if not line:
            break
        print(line.strip())
    file.close()



