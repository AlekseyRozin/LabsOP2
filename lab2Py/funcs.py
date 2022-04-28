import pickle

def getMinutes(time):
    semicolonIndex = time.find(':')
    hours = int(time[:semicolonIndex])
    minutes = int(time[semicolonIndex+1:])
    return hours * 60 + minutes


def getEndingTime(time):
    totalMinutesStart = getMinutes(time)
    totalMinutesEnd = totalMinutesStart + 105
    hoursEnd = totalMinutesEnd // 60
    minutesEnd = totalMinutesEnd % 60
    newTime = str(hoursEnd) + ':'
    newTime += '00' if minutesEnd == 0 else str(minutesEnd)
    return newTime


def validateLesson(lesson, lessons):
    if len(lessons) == 0:
        lesson["endTime"] = getEndingTime(lesson["startTime"])
        lessons.append(lesson)
        return lessons
    else:
        currMinutes = getMinutes(lesson["startTime"])
        prevMinutes = getMinutes(lessons[-1]["endTime"])
        minutesDiff = currMinutes - prevMinutes
        if minutesDiff < 5 or minutesDiff > 45:
            print('\nTurn cannot be more than 45 minutes and less than 5 minutes!')
            return lessons
        else:
            lesson["endTime"] = getEndingTime(lesson["startTime"])
            lessons.append(lesson)
            return lessons

def getLessons():
    lessons = []
    count = int(input('Enter how many lessons do you wanna add: '))
    i = 0
    while i < count:
        mySubject = {
            "subjectName": getName(),
            "startTime": getStartTime(),
            "endTime": ""
            }
        currentLen = len(lessons)
        lessons = validateLesson(mySubject, lessons)
        if len(lessons) != currentLen: i += 1
    return lessons

def getName():
    name = input('\nEnter name of the subject: ')
    while len(name) < 1:
        name = input('\nIncorrect length of name, try one more time: ')
    return name


def isTime(time):
    time = time.strip()
    if len(time) > 5 or len(time) < 5: return False
    elif time[2] != ':': return False
    elif not time[0].isdigit or not time[1].isdigit or not time[3].isdigit or not time[4].isdigit: return False
    elif int(time[:2]) > 23 or int(time[:2]) < 0: return False
    elif int(time[3:]) > 59 or int(time[3:]) < 0: return False
    return True


def getStartTime():
    startTime = input('Enter starting time of the lesson in this format [HH:MM]: ')
    while not isTime(startTime):
        startTime = input('Incorrect time format, try one more time: ')
    return startTime


def writeToFile(fileName, lessons):
    ans = input("Do you want to rewrite information (Y/N)? ")
    while ans != 'Y' and ans != 'y' and ans!= 'N' and ans!='n':
        ans = input("Wrong, enter 'Y' or 'N': ")

    if ans == 'Y' or 'y':file = open(fileName, 'wb')
    else: file = open(fileName, 'ab')
    pickle.dump(lessons, file)
    file.close()



def getFileText(fileName):
    file = open(fileName, 'rb')
    lessons = pickle.load(file)
    for lesson in lessons:
        res = lesson["subjectName"] + ", " + lesson["startTime"] + ", " + lesson["endTime"]
        print(res)
    file.close()

