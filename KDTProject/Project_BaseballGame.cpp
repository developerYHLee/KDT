#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

int computerNum[3];

vector<int> split(string str) {
	int n;
	vector<int> res;
	stringstream sstream(str);
	while (sstream >> n) res.push_back(n);

	return res;
}

void throwTheBall() {
	bool vis[10] = { false };

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++) {
		int num = rand() % 9 + 1;

		if (vis[num]) {
			i--;
			continue;
		}

		computerNum[i] = num;
	}
}

int main() {
	cout << "야구 게임\n";
	throwTheBall();

	int count = 0;
	while (true) {
		cout << "1~9 사이의 숫자 3개를 입력 하시오 (이외의 숫자 : 종료)\n";
		string num;
		getline(cin, num);
		vector<int> userNum = split(num);
		
		for (int i = 0; i < 3; i++) {
			if (userNum[i] <= 0 || userNum[i] > 9) {
				cout << "게임을 종료하였습니다.\n";
				return 0;
			}
		}

		count++;
		int strike = 0, ball = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (userNum[i] != computerNum[j]) continue;

				if (i == j) strike++;
				else ball++;
			}
		}

		if (strike == 3) break;

		cout << "Strike : " << strike << "\tBall : " << ball << endl;
	}

	cout << count << "번 만에 맞췄습니다.\n";
}