#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int num = 0;
bool sayNum(int count) {
	for (int i = 1; i <= count; i++) {
		num++;
		cout << num << endl;
		if (num == 31) return false;
	}
	return true;
}

int main() {
	srand((unsigned int)time(NULL));

	while (true) {
		cout << "������ �Է��ϼ��� : ";
		int count;
		cin >> count;

		if (count < 1 || count > 3) {
			cout << "1~3 ������ ���� �Է��ϼ���.\n\n";
			continue;
		}

		cout << "����ڰ� �θ� ����!\n";
		if (!sayNum(count)) {
			cout << "���� ����! ������� �й��Դϴ�.\n";
			break;
		}

		int computer = rand() % 3 + 1;
		cout << "\n��ǻ�Ͱ� �θ� ����!\n";
		if (!sayNum(computer)) {
			cout << "���� ����! ������� �¸��Դϴ�.\n";
			break;
		}

		cout << endl;
	}
}