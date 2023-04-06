#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	vector<string> vis;
	vis.push_back("airplane");

	time_t start, finish;
	start = time(NULL);

	int size = vis.size();
	while (true) {
	start:
		size = vis.size();

		for (int i = 0; i < size - 1; i++) cout << vis[i] << "->";
		
		if (size > 0) cout << vis[size - 1] << endl;
		
		cout << "다음 단어를 입력하세요 : ";
		string word;
		cin >> word;

		finish = time(NULL);
		if ((double)(finish - start) > 30) break;

		for (string str : vis) {
			if (str.compare(word) == 0) {
				cout << "중복된 단어입니다.\n\n";
				goto start;
			}
		}

		string str = vis[size - 1];
		if (str[str.length() - 1] == word[0]) vis.push_back(word);
		else cout << "잘못된 입력입니다.\n";

		cout << endl;
	}

	cout << "\n타임 오버!\n게임 종료!\n총 입력된 단어 개수 : " << size - 1 << endl;
}