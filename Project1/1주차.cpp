#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace Seoul {
	string number, landmark;
}

namespace Busan {
	string number, landmark;
}

using namespace Busan;
int main() {
	Seoul::number = "02";
	Seoul::landmark = "��ȭ��";
	number = "051";
	landmark = "���ȸ�";
	cout << "���� ������ȣ�� ���帶ũ ��� : " << Seoul::number << ' ' << Seoul::landmark << endl;
	cout << "�λ� ������ȣ�� ���帶ũ ��� : " << number << ' ' << landmark << endl << endl;


	bool vis[26] = { false };
	vector<char> alpha;
	cout << "�Է� ���� : ";
	string str1;
	getline(cin, str1);

	for (int i = 0; i < str1.length(); i++) {
		int index = str1[i] - 'a';

		if (index >= 0 && index < 26 && !vis[index]) {
			vis[index] = true;
			alpha.push_back(str1[i]);
		}
	}

	int sum4 = 0;
	for (int i = 0; i < 26; i++) {
		if (vis[i]) sum4++;
	}
	cout << "��¿��� : " << sum4 << "�� (";
	for (int i = 0; i < alpha.size() - 1; i++) cout << ' ' << alpha[i] << ',';
	cout << ' ' << alpha[alpha.size() - 1] << ')' << endl << endl;

	vector<int> v2;

	cout << "����ڰ� �Է��� ���� ���ϱ�" << endl << endl;
	while (true) {
		int num;
		cout << "���ڸ� �Է��ϼ��� (0 : exit) : ";
		cin >> num;

		if (num == 0) break;

		v2.push_back(num);
	}

	int sum1 = 0;
	for (int i : v2) sum1 += i;
	cout << "����ڰ� �Է��� ���� ���� : " << sum1 << endl << endl;

	int x, y;
	while (true) {
		cout << "x�� �Է��ϼ��� : ";
		cin >> x;

		cout << "y�� �Է��ϼ��� : ";
		cin >> y;

		if (x > 0 && y > 0) break;

		cout << "x�� y ��� ����� �Է����ּ���." << endl;
	}

	vector<vector<int>> v1 = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) cout << v1[i][j] << ' ';
		cout << endl;
	}

	return 0;
}