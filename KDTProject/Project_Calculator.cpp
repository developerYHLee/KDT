#include <iostream>

using namespace std;

class TestOperator {
public:
	static double num;
	double n;
	char oper;

	virtual void add(double n) {
		cout << "TestOperator Ŭ������ add �Լ� ȣ��\n";
	}
	virtual void sub(double n) {
		cout << "TestOperator Ŭ������ sub �Լ� ȣ��\n";
	}
	virtual void mul(double n) {
		cout << "TestOperator Ŭ������ mul �Լ� ȣ��\n";
	}
	virtual void div(double n) {
		cout << "TestOperator Ŭ������ div �Լ� ȣ��\n";
	}
	void reset() {
		TestOperator::num = 0;

		cout << "���ڸ� �Է����ּ��� : ";
		cin >> TestOperator::num;

		cout << "�����ڸ� �Է����ּ��� : ";
		cin >> oper;

		cout << "���ڸ� �Է����ּ��� : ";
		cin >> n;
	}
	void y() {
		cout << "�����ڸ� �Է����ּ��� : ";
		cin >> oper;

		cout << "���ڸ� �Է����ּ��� : ";
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
	cout << "------------------------------\n��� : " << TestOperator::num << "\n------------------------------\n";
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
			cout << "�߸��� �Է��� ���Խ��ϴ�. �ٽ� �Է��ϼ���.\n\n";
			break;
		}

		printRes();

		cout << "������ ��� �����Ͻðڽ��ϱ�? (Y : ���, AC : �ʱ�ȭ, EXIT : ����) : ";
		string s;
		cin >> s;

		if (s.compare("Y") == 0) calculator->y();
		else if (s.compare("AC") == 0) calculator->reset();
		else if (s.compare("EXIT") == 0) break;
		else cout << "�߸��� �Է��� ���Խ��ϴ�. ���α׷��� �����ϼ���.\n\n";
	}
}