from tkinter import *
from tkinter import messagebox 
window = Tk()

nextbutton = [None]*3
backbutton = [None]*3

for i in range(0,3):
    backbutton[i]=Button(window, text = "이전")
    nextbutton[i]=Button(window, text = "다음")

var = IntVar()

def quiz():
    if var.get() == 2:
        messagebox.showinfo("","정답입니다.")
    elif var.get() == 8:
        messagebox.showinfo("","정답입니다.")
    elif var.get() == 11:
        messagebox.showinfo("","정답입니다.")
    else:
        messagebox.showinfo("","오답입니다.")

imagelists = ["GIF/korea.GIF", "GIF/맹구.GIF", "GIF/남주혁.GIF"]
textlists = [ "사진 속 국기는 어느 나라 국기일까요?", "사진 속 캐릭터의 이름은 무엇일까요?", "사진 속 배우의 이름은 무엇일까요?" ]
answer = ["공백", "중국", "한국", "독일", "미국", "짱구", "훈이", "유리", "맹구", "남주역", "람주혁", "남주혁", "남수혁"]

label = [None]*3
photo = [None]*3
question = [None]*3
rb = [None] * 13

for i in range(0,3): #사진 출력
    photo[i]= PhotoImage(file = imagelists[i])
    label[i]=Label(window, image = photo[i])
    question[i]=Label(window, text = textlists[i])

for i in range(0, 13): 
    rb[i] = Radiobutton(window, text = answer[i], variable = var, value = i, command = quiz)

for i in range(1,5): #첫번째 문제 보이게 하는 거
    rb[i].pack(side=BOTTOM)

backbutton[0].pack(side=BOTTOM)
nextbutton[0].pack(side=BOTTOM)

label[0].pack(side=TOP)
question[0].pack(side=TOP)


def back1(a):#3에서 2으로 넘어가는거
    label[2].pack_forget()
    question[2].pack_forget()

    for i in range(9,13):
        rb[i].pack_forget()
        
    backbutton[2].pack_forget()
    nextbutton[2].pack_forget()
    
    label[1].pack(side=TOP)
    question[1].pack(side=TOP)

    for i in range(5,9):
        rb[i].pack(side=BOTTOM)
    
    backbutton[1].pack(side=BOTTOM)
    nextbutton[1].pack(side=BOTTOM)

def back2(a): #2에서 1으로 넘어가는거
    label[1].pack_forget()
    question[1].pack_forget()

    for i in range(5,9):
        rb[i].pack_forget()
    
    backbutton[1].pack_forget()
    nextbutton[1].pack_forget()
    
    label[0].pack(side=TOP)
    question[0].pack(side=TOP)

    for i in range(1,5):
        rb[i].pack(side=BOTTOM)
   
    backbutton[0].pack(side=BOTTOM)
    nextbutton[0].pack(side=BOTTOM)

def next1(a): #1에서 2로 넘어가는거
    label[0].pack_forget()
    question[0].pack_forget()
    
    for i in range(1,5):
        rb[i].pack_forget()
    
    backbutton[0].pack_forget()
    nextbutton[0].pack_forget()
    
    label[1].pack(side=TOP)
    question[1].pack(side=TOP)

    for i in range(5,9):
        rb[i].pack(side=BOTTOM)
    
    backbutton[1].pack(side=BOTTOM)
    nextbutton[1].pack(side=BOTTOM)

def next2(a): #2에서 3으로 넘어가는거
    label[1].pack_forget()
    question[1].pack_forget()

    for i in range(5,9):
        rb[i].pack_forget()

    backbutton[1].pack_forget()
    nextbutton[1].pack_forget()
    
    label[2].pack(side=TOP)
    question[2].pack(side=TOP)

    for i in range(9,13):
        rb[i].pack(side=BOTTOM)

    backbutton[2].pack(side=BOTTOM)
    nextbutton[2].pack(side=BOTTOM)

def end(a): #마지막 페이지에서 이전과 다음 누를 수 없을 때
    messagebox.showinfo("","마지막 페이지입니다!")

backbutton[0].bind("<Button-1>", end)
backbutton[1].bind("<Button-1>", back2)
backbutton[2].bind("<Button-1>", back1)

nextbutton[0].bind("<Button-1>", next1)
nextbutton[1].bind("<Button-1>", next2)
nextbutton[2].bind("<Button-1>", end)

window.mainloop()
