vending_machine = ['게토레이', '게토레이', '레쓰비', '생수', '이프로']

def check_machine():
    print(vending_machine)

def is_drink():
    drink = input("마시고 싶은 음료? ")
    if drink in vending_machine:
        print(drink, "드릴게요")
        vending_machine.remove(drink)
        print("남은 음료수: ", vending_machine)
    else:
        print(f"{drink}는 지금 없네요")

def add_drink():
    print("남은 음료수: ", vending_machine)
    drink = input("추가할 음료수? ")
    vending_machine.append(drink)
    vending_machine.sort()
    print("추가 완료")
    print("남은 음료수: ", vending_machine)

def remove_drink():
    print("남은 음료수: ", vending_machine)
    drink = input("삭제할 음료수? ")
    if drink in vending_machine:
        vending_machine.remove(drink)
        print("삭제 완료")
        print("남은 음료수: ", vending_machine)
    else:
        print(f"{drink}는 지금 없네요")

while(1):
    check_machine()

    who = int(input("사용자 종류를 입력하세요(1.소비자, 2.주인) : "))
    if who == 1:
        is_drink()
    else:
        todo = int(input("할 일 선택(1.추가, 2.삭제) : "))
        if todo == 1:
            add_drink()
        else:
            remove_drink()






