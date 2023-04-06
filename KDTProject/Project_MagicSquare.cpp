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
	cout << "�������� �� Ȥ�� ���� ���� �ڿ����� �Է����ּ��� : ";
	int N;
	cin >> N;

	int** map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		//0���� �ʱ�ȭ�Ѵ�.
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
		
		//���� ���� Ȯ���� �࿭�� 0�� �� ������ �ݺ��Ѵ�.
		if (map[col][row] != 0) { 
			col += 2; row--; 
			if (col >= N) col -= N;
			if (row < 0) row = N - 1;
		}
	}

	//�ڸ����� ����� ������ ��� �� ����ϰ� ���̰� �ϱ� ���� �����.
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