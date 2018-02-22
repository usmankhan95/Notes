from random import *                                            #use random package for random question output

legislators = { "Tsang Yok-sing" : "DAB", "Albert Ho" :         #define dictionary
"Democratic", "Lee Cheuk-yan" : "Labour", "James To" :          #define dictionary
"Democratic", "Chan Kam-lam" : "DAB", "Lau Wong-fat" :          #define dictionary
"Economic Synergy", "Emily Lau" : "Democratic" }                #define dictionary

names = list(legislators.keys())                                #assigning names to the keys in the dictionary
parties = list(legislators.values())                            #assigning parties to values in the dictionary

numberCorrect = 0                                               #create numberCorrect var, starts at 0

for i in range(0, 5):                                           #for loop from 0,5 for 5 questions
    name = names[randrange(len(names))]                         #randomly placing a legislator into name var
    party = parties[randrange(len(parties))]                    #randomly placing a party into party var
    ans = input("Does "+name+" belong to "+party+" (Y/N)?")     #output question with random variables
    if ans.upper() == 'Y':                                      #changing lower case to uppercase
                                                                #Checking if answer is equal to Y
        if legislators[name] == party:                          #if it is Y then check if name matches party

            print("Correct!")                                   #name matches party output correct
            numberCorrect+=1                                    #add 1 to numberCorrect variable

        else:
            print("You are incorrect!")                         #if name does not match party then incorrect

    elif ans.upper() == 'N':                                    #else if statement for N answer

        if legislators[name] == party:                          #check again if name match party

            print ("You are incorrect!")                        #if match and answer is N then incorrect
        else:

            print("Correct!")                                   #else print correct
            numberCorrect+=1

print("You were correct", numberCorrect,"out of 5 times!")      #finally output numberCorrect variable
