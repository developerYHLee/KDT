#include <iostream>
#include <cstring>

using namespace std;

int makeDigit(int num) {
	int res = 0;
	while (num > 0) {
		num /= 10;
		res++;
	}

	return res;
}

int main() {
	cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요 : ";
	int N;
	cin >> N;

	int** map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		//0으로 초기화한다.
		memset(map[i], 0, sizeof(map[i]) * N);
	}
	
	int count = 0, row = N / 2, col = 0;
	
	while (true) {
		map[col][row] = ++count;

		if (count >= N * N) break;

		col--;
		row++;

		if (col < 0) col = N - 1;
		if (row >= N) row = 0;
		
		//다음 번에 확인할 행열이 0이 될 때까지 반복한다.
		if (map[col][row] != 0) { 
			col += 2; row--; 
			if (col >= N) col -= N;
			if (row < 0) row = N - 1;
		}
	}

	//자릿수를 만드는 이유는 출력 시 깔끔하게 보이게 하기 위해 만든다.
	int digit = makeDigit(N * N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num_digit = makeDigit(map[i][j]);
			for (int k = num_digit; k < digit; k++) cout << ' ';
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) delete[] map[i];
	delete[] map;
}