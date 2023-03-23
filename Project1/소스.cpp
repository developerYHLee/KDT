#include <iostream>

using namespace std;

int main() {
	cout << "나이를 입력하세요 : ";
	int age;
	cin >> age;

	if (age > 0 && age < 8) cout << "유아\n";
	else if (age >= 8 && age <= 13) cout << "초등학생\n";
	else if (age >= 14 && age <= 16) cout << "중학생\n";
	else if (age >= 17 && age <= 19) cout << "고등학생\n";
	else if (age >= 20) cout << "성인\n";
	else cout << "나이가 너무 많습니다..!\n";
	cout << "\n이름을 입력하세요 : ";
	string name;
	cin >> name;

	if (name == "홍길동") cout << "남자\n";
	else if (name == "성춘향") cout << "여자\n";
	else cout << "모르겠어요.\n";
	cout << "\n숫자를 입력하세요 : ";
	int num;
	cin >> num;
	num % 5 == 0 ? cout << num << "는 5의 배수입니다.\n" : cout << num << "는 5의 배수가 아니에요ㅜㅜ\n";
	cout << "\n연산할 정수 두 개를 입력해 주세요 : ";
	int n1, n2;
	cin >> n1;
	cin >> n2;

	cout << "연산자를 입력해주세요. (+ - * /) : ";
	char op;
	cin >> op;

	cout << "연산 결과 : ";
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
		cout << "몫 : " << n1 / n2 << " 나머지 : " << n1 % n2;
		break;

	}

	return 0;
}