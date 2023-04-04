money = int(input("교환할 돈은 얼마?"))

c500 = money // 500

c100 = money % 500 // 100

c50 = money % 500 % 100 // 50

c10 = money % 500 % 100 % 50 // 10

remain = money % 500 % 100 % 50 % 10

print("500원짜리 ==> ", c500)
print("100원짜리 ==> ", c100)
print("50원짜리 ==> ", c50)
print("10원짜리 ==> ", c10)
print("바꾸찌못한돈 ==> ", remain)

