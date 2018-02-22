# open and read file student / score
def openRead():
    student_file = open("Student.txt", "r")
    score_file = open("Score.txt", "r")
    student = student_file.read().split(' ')
    score = score_file.read().split(' ')
    return (student, score)

def scoreAverage():
    addedScore = 0.0                    #creating variables for later use.
    average = 0.0
    student, score = openRead()

    for i in range(0,len(student)):     #for loop to display student scores.

        print("Student: "+student[i]+" Final: "+score[i])          
        addedScore = addedScore + float(score[i])

    average = addedScore/10             #Divide by how many students to get average.
    print("The class average is:", average, "\n")
    return


def grade():
    student, score = openRead()
    
    for i in range(0,len(student)):

        if float(score[i]) >= 90:       #if statements for grade boundaries
        
            print("Student: "+student[i]+" Final Grade: A")
                      
        elif float(score[i]) >= 80:

            print("Student: "+student[i]+" Final Grade: B")

        elif float(score[i]) >= 70:

            print("Student: "+student[i]+" Final Grade: C")

        elif float(score[i]) >= 60:

            print("Student: "+student[i]+" Final Grade: D")

        else:
        
            print("Invalid")
            
    return

def studentAGrade():
    student, score = openRead()
    count = 0

    for i in range(0,len(student)):

        if float(score[i]) >= 90:

            count = count + 1            #count variable to find out how many students got an A

    print("The class has",count,"students that got an A grade") 
    return

    

openRead()                  #A function to read student.txt and score.txt files
scoreAverage()              #A function to output student score and find the average
print("Grade distribution")
grade()                     #A function to output the grade
studentAGrade()             #A function to find number of students got grade A
