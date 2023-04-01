#include <iostream>

using namespace std;

class Snack {
public:
	int price;
	string name, company;

	Snack(int price, string name, string company) {
		this->price = price;
		this->name = name;
		this->company = company;
	}

	virtual void printInfo() {
		cout << "이름 : " << name << " 회사 : " << company << " 가격 : " << price;
	}
};

class Candy : public Snack {
public:
	string taste;

	Candy(int price, string name, string company, string taste) : Snack(price, name, company) {
		this->taste = taste;
	}

	void printInfo() {
		Snack::printInfo();
		cout << " 맛 : " << taste;
	}
};

class Chocolate : public Snack {
public:
	string shape;

	Chocolate(int price, string name, string company, string shape) : Snack(price, name, company) {
		this->shape = shape;
	}

	void printInfo() {
		Snack::printInfo();
		cout << " 모양 : " << shape;
	}
};

int main() {
	Snack** snackBasket = new Snack * [4]{ new Candy(1000, "맛있는 캔디", "오00", "달다"), new Candy(1200, "몸에 좋은 캔디", "정00", "쓰다") , new Chocolate(700, "초코바", "오00", "사각형"), new Chocolate(1000, "딸기초코바", "아오00", "원") };

	for (int i = 0; i < 4; i++) {
		snackBasket[i]->printInfo();
		cout << endl;
	}
	
	for (int i = 0; i < 4; i++) delete[] snackBasket[i];
	delete[] snackBasket;
}