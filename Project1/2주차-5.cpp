#include <iostream>
#include <vector>

#include "Snack.h"

using namespace std;


int main() {
	while (true) {
		cout << "���� �ٱ��Ͽ� �߰��� ������ ���ÿ�. (1 : ����, 2 : ���ݸ�, 0 : ����) : ";
		int num;
		cin >> num;

		string str;
		if (num == 0) break;
		else if (num == 1) {
			cout << "���� �Է��ϼ��� : ";
			cin >> str;
			str += "�� ����";
			Snack::hasSnack.push_back(str);
			Snack::count++;
		}
		else if (num == 2) {
			cout << "����� �Է��ϼ��� : ";
			cin >> str;
			str += "��� ���ݸ�";
			Snack::hasSnack.push_back(str);
			Snack::count++;
		}
		else cout << "0~2 ������ ���ڸ� �Է��ϼ���." << endl;
		cout << endl;
	}

	Snack::printSnack();
}