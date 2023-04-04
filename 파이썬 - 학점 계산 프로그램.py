def getGrade(score):

    
    if score >= 90 :
        grade = 'A'
      
    elif score >= 80 :
        grade = 'B'
      
    elif score >= 70 :
        grade = 'C'
      
    elif score >= 60 :
        grade = 'D'
      
    else :
        grade = 'F'

    return grade

def getAvg(a,b):
    average=0
    average = (a+b)/2

    return average

korean = int(input("국어성적 :"))
math = int(input("수학성적 :"))

a = getAvg(korean,math)
print("학점은 %c입니다." %getGrade(a));
