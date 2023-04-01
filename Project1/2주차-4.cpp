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
		cout << "�̸� : " << name << " ȸ�� : " << company << " ���� : " << price;
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
		cout << " �� : " << taste;
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
		cout << " ��� : " << shape;
	}
};

int main() {
	Snack** snackBasket = new Snack * [4]{ new Candy(1000, "���ִ� ĵ��", "��00", "�޴�"), new Candy(1200, "���� ���� ĵ��", "��00", "����") , new Chocolate(700, "���ڹ�", "��00", "�簢��"), new Chocolate(1000, "�������ڹ�", "�ƿ�00", "��") };

	for (int i = 0; i < 4; i++) {
		snackBasket[i]->printInfo();
		cout << endl;
	}
	
	for (int i = 0; i < 4; i++) delete[] snackBasket[i];
	delete[] snackBasket;
}