#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	
	cout << "로또 당첨 번호\n";

	bool vis[47] = { false };
	for (int i = 0; i < 6; i++) {
		int randNum = rand() % 46 + 1;
		if (vis[randNum]) {
			i--;
			continue;
		}

		vis[randNum] = true;
		cout << randNum << ' ';
	}
}