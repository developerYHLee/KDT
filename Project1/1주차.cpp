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
	Seoul::landmark = "광화문";
	number = "051";
	landmark = "광안리";
	cout << "서울 지역번호와 랜드마크 출력 : " << Seoul::number << ' ' << Seoul::landmark << endl;
	cout << "부산 지역번호와 랜드마크 출력 : " << number << ' ' << landmark << endl << endl;


	bool vis[26] = { false };
	vector<char> alpha;
	cout << "입력 예시 : ";
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
	cout << "출력예시 : " << sum4 << "개 (";
	for (int i = 0; i < alpha.size() - 1; i++) cout << ' ' << alpha[i] << ',';
	cout << ' ' << alpha[alpha.size() - 1] << ')' << endl << endl;

	vector<int> v2;

	cout << "사용자가 입력한 숫자 더하기" << endl << endl;
	while (true) {
		int num;
		cout << "숫자를 입력하세요 (0 : exit) : ";
		cin >> num;

		if (num == 0) break;

		v2.push_back(num);
	}

	int sum1 = 0;
	for (int i : v2) sum1 += i;
	cout << "사용자가 입력한 수의 합은 : " << sum1 << endl << endl;

	int x, y;
	while (true) {
		cout << "x를 입력하세요 : ";
		cin >> x;

		cout << "y를 입력하세요 : ";
		cin >> y;

		if (x > 0 && y > 0) break;

		cout << "x와 y 모두 양수를 입력해주세요." << endl;
	}

	vector<vector<int>> v1 = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	for (int i = 0; i < v1.size(); i++) {
		for (int j = 0; j < v1[i].size(); j++) cout << v1[i][j] << ' ';
		cout << endl;
	}

	return 0;
}