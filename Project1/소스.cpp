#include <iostream>

using namespace std;

int main() {
	cout << "���̸� �Է��ϼ��� : ";
	int age;
	cin >> age;

	if (age > 0 && age < 8) cout << "����\n";
	else if (age >= 8 && age <= 13) cout << "�ʵ��л�\n";
	else if (age >= 14 && age <= 16) cout << "���л�\n";
	else if (age >= 17 && age <= 19) cout << "����л�\n";
	else if (age >= 20) cout << "����\n";
	else cout << "���̰� �ʹ� �����ϴ�..!\n";
	cout << "\n�̸��� �Է��ϼ��� : ";
	string name;
	cin >> name;

	if (name == "ȫ�浿") cout << "����\n";
	else if (name == "������") cout << "����\n";
	else cout << "�𸣰ھ��.\n";
	cout << "\n���ڸ� �Է��ϼ��� : ";
	int num;
	cin >> num;
	num % 5 == 0 ? cout << num << "�� 5�� ����Դϴ�.\n" : cout << num << "�� 5�� ����� �ƴϿ���̤�\n";
	cout << "\n������ ���� �� ���� �Է��� �ּ��� : ";
	int n1, n2;
	cin >> n1;
	cin >> n2;

	cout << "�����ڸ� �Է����ּ���. (+ - * /) : ";
	char op;
	cin >> op;

	cout << "���� ��� : ";
	switch (op) {
	case '+' :
		cout << n1 + n2;
		break;
	case '-' :
		cout << n1 - n2;
		break;
	case '*':
		cout << n1 * n2;
		break;
	case '/':
		cout << "�� : " << n1 / n2 << " ������ : " << n1 % n2;
		break;

	}

	return 0;
}