from tkinter import *
from tkinter import messagebox 
window = Tk()
var = IntVar()

label = [None]*2  #공간 마련
photo = [None]*5
rb = [None] * 8
text = [None]*4
button = [None]*4

def beginning(): #첫 화면으로 초기화 시키는 버튼
    remove()
    label.pack()
    
def menu():
    if var.get() == 0:
        messagebox.showinfo("SWU 피씨방", "아메리카노 주문 성공!")
    elif var.get() == 1:
        messagebox.showinfo("SWU 피씨방","바닐라 라떼 주문 성공!")
    elif var.get() == 2:
        messagebox.showinfo("SWU 피씨방","블루베리 에이드 주문 성공!")
    elif var.get() == 3:
        messagebox.showinfo("SWU 피씨방","오렌지 에이드 주문 성공!")
    elif var.get() == 4:
        messagebox.showinfo("SWU 피씨방","딸기 케이크 주문 성공!")
    elif var.get() == 5:
        messagebox.showinfo("SWU 피씨방","초코 케이크 주문 성공!")
    elif var.get() == 6:
        messagebox.showinfo("SWU 피씨방","멜론 빵 주문 성공!")
    elif var.get() == 7:
        messagebox.showinfo("SWU 피씨방","브라우니 주문 성공!")

def remove():
    for i in range(0,4):
        button[i].place_forget()
    for i in range(0,2):
        text[i].place_forget()
    for i in range(0,8):
        rb[i].pack_forget()
    label.pack_forget()
    
def drink_start():
    label.pack_forget()
    button[0].place(x=0, y=80) 
    button[1].place(x=700, y=80)
    text[0].place(x=600, y=0)
    beginbutton.pack(side = BOTTOM)
    label2.pack(side = BOTTOM)
    
    
def coffee():
    remove()
    rb[0].pack()
    rb[1].pack()

def aid():
    remove()
    rb[2].pack()
    rb[3].pack()

def dessert_start():
    label.pack_forget()
    button[2].place(x=0, y=80) 
    button[3].place(x=400, y=80)
    text[1].place(x=150, y=0)
    beginbutton.pack(side = BOTTOM)
    label2.pack(side = BOTTOM)

def cake():
    remove()
    rb[4].pack()
    rb[5].pack()

def bread():
    remove()
    rb[6].pack()
    rb[7].pack()

def refund():
    messagebox.showinfo("", "카운터로 오시면 남은 시간 환불해드리겠습니다.")

def plus():
    messagebox.showinfo("", "연장 되었습니다.")

beginbutton = Button(window, text = "초기화면으로 가기", command = beginning)
label2 = Label(window, text = "한 번 주문 후 꼭 초기화면으로 간 후 재주문 해주세요 ~ ") #레이블2

imagelists = ["커피.GIF", "에이드.GIF","케아크.GIF", "빵.GIF", "PC.gif"]
textlists = ["원하시는 음료의 종류를 선택해주세요 ^^", "원하시는 디저트의 종류를 선택해주세요 ^^"]
answer = ["아메리카노 주문하기", "바닐라 라떼  주문하기", "블루베리 에이드 주문하기", "오렌지 에이드 주문하기", "딸기 케이크 주문하기", "초코 케이크 주문하기", "멜론 빵 주문하기","브라우니 주문하기"]
commandlists = ["coffee", "aid", "cake", "bread"]

for i in range(0,5):
    photo[i]= PhotoImage(file = imagelists[i])

for i in range(0,8):
    rb[i] = Radiobutton(window, text = answer[i], variable = var, value = i, command = menu)

for i in range(0,2):
    text[i]=Label(window, text = textlists[i])

for i in range(0,4):
    button[i] = Button(window, image = photo[i], command = commandlists[i])

mainmenu = Menu(window) #메뉴 두 개
window.config(menu = mainmenu)

filemenu = Menu(mainmenu)
mainmenu.add_cascade(label = "먹거리 주문", menu = filemenu)
filemenu.add_command(label = "음료", command = drink_start)
filemenu.add_separator()
filemenu.add_command(label = "음식", command = dessert_start)

filemenu2 = Menu(mainmenu)
mainmenu.add_cascade(label = "시간", menu = filemenu2)
openmenu = Menu(filemenu2)
filemenu2.add_cascade(label = "연장", menu = openmenu)
filemenu.add_separator()
filemenu2.add_cascade(label = "환불", command = refund)
openmenu.add_command(label = "30분 연장", command = plus)
openmenu.add_command(label = "1시간 연장", command = plus)
openmenu.add_command(label = "3시간 연장", command = plus)

label = Label(window, image = photo[4]) #첫 화면(레이블1)
label.pack()

window.mainloop()
