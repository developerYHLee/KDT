#include <iostream>

int add(int a, int b);
int sub(int a, int b);
int multiple(int a, int b);
float divide(int a, int b);
void isOdd(int num);
int findMax(int, int, int);
using namespace std;

int main() {
	int a = 7, b = 12, c = -7;

	cout << "a : " << a << " b : " << b << '\n';
	cout << "add : " << add(a, b) << '\n';
	cout << "minus : " << sub(a, b) << '\n';
	cout << "multiple : " << multiple(a, b) << '\n';
	cout << "divide : " << divide(a, b) << '\n';
	isOdd(a);
	cout << a << "�� " << b << "�� " << c << " �� ���� ū �� : " << findMax(a, b, c);
	return 0;
}


int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return max(a, b) - min(a, b);
}

int multiple(int a, int b) {
	return a * b;
}

float divide(int a, int b) {
	return (float)a / b;
}

void isOdd(int num) {
	if (num % 2 == 0) cout << num << "��(��) ¦���Դϴ�.\n";
	else cout << num << "��(��) Ȧ���Դϴ�.\n";
}

int findMax(int a, int b, int c) {
	return max(a, max(b, c));
}