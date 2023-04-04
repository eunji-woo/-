a=1
b=c=d=sum1=sum2=sum3=0

while True:
    print("==== 슈먼 카페 ====")
    print("1. 아메리카노: 2000원")
    print("2. 카페라떼: 2500원")
    print("3. 마끼아또: 3000원")
    print("4. 주문종료\n")

    a=int(input("메뉴를 입력해주세요 =>"))

    if a==1 :
        b=int(input("수량을 입력해주세요 =>"))
        sum1=sum1+b
        print("\n**** 총 주문내역 ****")
        print("1. 아메리카노: %d잔"%sum1)
        print("2. 카페라떼: %d잔"%sum2)
        print("3. 마끼아또: %d잔"%sum3)
        print("총금액 : %d원\n" %(2000*sum1+sum2*2500+sum3*3000))


    elif a==2 :
        c=int(input("수량을 입력해주세요 =>"))
        sum2=sum2+c
        print("\n**** 총 주문내역 ****")
        print("1. 아메리카노: %d잔"%sum1)
        print("2. 카페라떼: %d잔"%sum2)
        print("3. 마끼아또: %d잔"%sum3)
        print("총금액 : %d원\n" %(2000*sum1+sum2*2500+sum3*3000))

    elif a==3 :
        d=int(input("수량을 입력해주세요 =>"))
        sum3=sum3+d
        print("\n**** 총 주문내역 ****")
        print("1. 아메리카노: %d잔"%sum1)
        print("2. 카페라떼: %d잔"%sum2)
        print("3. 마끼아또: %d잔"%sum3)
        print("총금액 : %d원\n" %(2000*sum1+sum2*2500+sum3*3000))
    
    elif a==4 :
        print("주문을 종료합니다.")
        print("\n**** 총 주문내역 ****")
        print("1. 아메리카노: %d잔" %sum1)
        print("2. 카페라떼 : %d잔" %sum2)
        print("3. 마끼아또 : %d잔:" %sum3)
        print("총금액 : %d원\n" %(2000*sum1+sum2*2500+sum3*3000))
        break

    else :
        print("잘못 입력되었습니다. 다시 입력해주세요.")
        print("\n**** 총 주문내역 ****")
        print("1. 아메리카노: %d잔"%sum1)
        print("2. 카페라떼: %d잔"%sum2)
        print("3. 마끼아또: %d잔"%sum3)
        print("총금액 : %d원\n" %(2000*sum1+sum2*2500+sum3*3000))
        continue

