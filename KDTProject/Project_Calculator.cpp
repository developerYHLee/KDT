#include <iostream>

using namespace std;

class TestOperator {
public:
	static double num;
	double n;
	char oper;

	virtual void add(double n) {
		cout << "TestOperator 클래스의 add 함수 호출\n";
	}
	virtual void sub(double n) {
		cout << "TestOperator 클래스의 sub 함수 호출\n";
	}
	virtual void mul(double n) {
		cout << "TestOperator 클래스의 mul 함수 호출\n";
	}
	virtual void div(double n) {
		cout << "TestOperator 클래스의 div 함수 호출\n";
	}
	void reset() {
		TestOperator::num = 0;

		cout << "숫자를 입력해주세요 : ";
		cin >> TestOperator::num;

		cout << "연산자를 입력해주세요 : ";
		cin >> oper;

		cout << "숫자를 입력해주세요 : ";
		cin >> n;
	}
	void y() {
		cout << "연산자를 입력해주세요 : ";
		cin >> oper;

		cout << "숫자를 입력해주세요 : ";
		cin >> n;
	}
};

double TestOperator::num = 0;

class TestAdd : public TestOperator {
public:
	void add(double n) { TestOperator::num += n; }
};
class TestSubtract : public TestOperator {
public:
	void sub(double n) { TestOperator::num -= n; }
};
class TestMultiply : public TestOperator {
public:
	void mul(double n) { TestOperator::num *= n; }
};
class TestDivide : public TestOperator {
public:
	void div(double n) { TestOperator::num /= n; }
};

void printRes() {
	cout << "------------------------------\n결과 : " << TestOperator::num << "\n------------------------------\n";
}

int main() {
	TestOperator* calculator = new TestOperator();
	calculator->reset();

	while (true) {
		double n = calculator->n;
		switch (calculator->oper)
		{
		case '+':
			calculator = new TestAdd();
			calculator->add(n);
			break;
		case '-':
			calculator = new TestSubtract();
			calculator->sub(n);
			break;
		case '*':
			calculator = new TestMultiply();
			calculator->mul(n);
			break;
		case '/':
			calculator = new TestDivide();
			calculator->div(n);
			break;
		default:
			cout << "잘못된 입력이 들어왔습니다. 다시 입력하세요.\n\n";
			break;
		}

		printRes();

		cout << "연산을 계속 진행하시겠습니까? (Y : 계속, AC : 초기화, EXIT : 종료) : ";
		string s;
		cin >> s;

		if (s.compare("Y") == 0) calculator->y();
		else if (s.compare("AC") == 0) calculator->reset();
		else if (s.compare("EXIT") == 0) break;
		else cout << "잘못된 입력이 들어왔습니다. 프로그램을 종료하세요.\n\n";
	}
}