#include <iostream>

using namespace std;

class Parent {
public:
	virtual void test() {
		cout << "부모 클래스의 가상 함수 호출!" << endl;
	}
};

class Child : public Parent {
	void test() {
		cout << "자식 클래스의 가상 함수 호출!" << endl;
	}
};

int main() {
	Parent** child = new Parent*[3]{ new Child(), new Child() ,new Child() };
	child[0]->test();
}