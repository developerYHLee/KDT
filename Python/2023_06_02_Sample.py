class Calcul:
    def __init__(self, num1, num2):
        self.num1 = num1
        self.num2 = num2

    def add(self):
        return self.num1 + self.num2

    def sub(self):
        return self.num1 - self.num2

    def mul(self):
        return self.num1 * self.num2

    def div(self):
        return self.num1 / self.num2

    def show(self):
        print(f"{self.num1} + {self.num2} = {self.num1 + self.num2}")
        print(f"{self.num1} - {self.num2} = {self.num1 - self.num2}")
        print(f"{self.num1} * {self.num2} = {self.num1 * self.num2}")
        print(f"{self.num1} / {self.num2} = {self.num1 / self.num2}")

cal = Calcul(15, 4)
cal.show()
print()

class Supermarket:
    def __init__(self, location, name, product, customer):
        self.loc = location
        self.name = name
        self.pro = product
        self.cust = customer

    def print_location(self):
        print(f"현재 위치 : {self.loc}")

    def change_category(self, new_product):
        self.pro = new_product
        print(f"파는 물건이 {self.pro}로 변경되었습니다.")

    def show_list(self):
        print(f"현재 파는 물건 {self.pro}")

    def enter_customer(self):
        self.cust += 1
        print(f"손님이 {self.cust}명으로 증가했습니다.")

    def show_info(self):
        print(f"가게 이름 : {self.name}")
        print(f"가게 위치 : {self.loc}")
        print(f"파는 물건 : {self.pro}")
        print(f"손님 수 : {self.cust}")

supermarket = Supermarket("서울 마포구", "코딩온 마트", "전공 서적", 14)
supermarket.show_info()
supermarket.print_location()
supermarket.change_category("코딩 관련 서적")
supermarket.show_list()
supermarket.enter_customer()
print()

class Character:
    def __init__(self, name):
        self.name = name
        self.level = 0
        self.item_num = 0

    def startgame(self):
        while True:
            order = int(input("명령을 입력하세요(0 : 종료, 1 : 이름 변경, 2 : level up, 3 : item 줍기, 4 : item 사용, 5 : 정보 출력) : "))

            if order == 0: break
            elif order == 1:
                new_name = input("변경할 이름을 입력하세요 : ")
                self.name = new_name
            elif order == 2:
                self.level += 1
            elif order == 3:
                self.item_num += 1
            elif order == 4:
                if self.item_num <= 0:
                    print("아이템이 없습니다!")
                else:
                    print("아이템 사용!")
                    self.item_num -= 1
            elif order == 5:
                print(f"이름 : {self.name}")
                print(f"level : {self.level}")
                print(f"item 수 : {self.item_num}")

player = input("캐릭터의 이름을 설정하세요 : ")
character = Character(player)
character.startgame()