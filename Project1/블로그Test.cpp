#include <iostream>

using namespace std;

class Parent {
public:
	virtual void test() {
		cout << "�θ� Ŭ������ ���� �Լ� ȣ��!" << endl;
	}
};

class Child : public Parent {
	void test() {
		cout << "�ڽ� Ŭ������ ���� �Լ� ȣ��!" << endl;
	}
};

int main() {
	Parent** child = new Parent*[3]{ new Child(), new Child() ,new Child() };
	child[0]->test();
}