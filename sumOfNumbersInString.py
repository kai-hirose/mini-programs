def sumOfNumbersInString(input: str) -> int:
    temp = ""
    sum = 0
    for i in range(0, len(input)):
        ch = input[i]
        #Continous digits get added to temp.
        if ch.isdigit():
            temp += ch
        #Nondigits indicate a separation between numbers so we add it to the sum.
        #Make sure temp is not empty.
        else:
            if(len(temp)>0):
                sum += int(temp)
                temp = ""

    #Check if temp is empty or not, if it is, we still need to add temp to the sum before returning.
    #Otherwise, just return the sum.
    if(len(temp)>0):
        return sum + int(temp)
    else:
        return sum

'''
I did not want to make unit test files so I do the checking here.
'''
if(sumOfNumbersInString("1x2x3")==6 and
   sumOfNumbersInString("12x3x")==15 and
   sumOfNumbersInString("x442x3x")==445 and
   sumOfNumbersInString("1  3   ")==4):
    print("Success")
else:
    print("Fail")
