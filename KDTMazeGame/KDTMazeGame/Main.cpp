#include <iostream>
#include <stack>

#include "Board.h"

using namespace std;

bool** isWall;

void printDir(int i) {
	if (i == 0) cout << " �� : 0";
	else if (i == 1) cout << " �� : 1";
	else if (i == 2) cout << " �� : 2";
	else cout << " �� : 3";
}

int* move(int order, int row, int col, int size) {
	int* res = new int[3];
	int vis = 0;

	res[0] = row;
	res[1] = col;
	res[2] = vis;

	if (order == 0) {
		row--;
		if (row < 0 || isWall[row][col]) cout << "���� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "���� �̵�!\n\n";
			res[0] = row;
			res[2] = 1;
		}
	}
	else if (order == 1) {
		row++;
		if (row >= size || isWall[row][col]) cout << "�Ʒ��� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "�Ʒ��� �̵�!\n\n";
			res[0] = row;
			res[2] = 0;
		}
	}
	else if (order == 2) {
		col--;
		if (col < 0 || isWall[row][col]) cout << "�������� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "���ʷ� �̵�!\n\n";
			res[1] = col;
			res[2] = 3;
		}
	}
	else {
		col++;
		if (col >= size || isWall[row][col]) cout << "���������� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "�����ʷ� �̵�!\n\n";
			res[1] = col;
			res[2] = 2;
		}
	}

	return res;
}

int main() {
	cout << "�̷��� ũ�⸦ �Է��ϼ���. (Ȧ���� �Է�) : ";
	int size;
	cin >> size;

	Board board(size);
	cout << "\n\n";
	
	isWall = board.getIsWall();
	stack<pair<int, int>> S;
	
	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };
	
	int curRow = 0, curCol = 0, vis = 0;
	while (true) {
		cout << "�̵� ������ ����(";

		int pathCount = 0;
		for (int i = 0; i < 4; i++) {
			int row = curRow + dx[i];
			int col = curCol + dy[i];

			if (row < 0 || col < 0 || row >= size || col >= size || isWall[row][col]) continue;
			
			printDir(i);
			if (vis == i) cout << "(��� ������ ��)";
			else pathCount++;
		}
		cout << " ) : ";
		if (pathCount == 0) {
			cout << "���ư����մϴ�!\n\n";

		}
		
		int order;
		cin >> order;

		int *path = move(order, curRow, curCol, size);
		

		if (curRow == size - 2 && curCol == size - 1) {
			cout << "�̷θ� �������Խ��ϴ�!\n";
			break;
		}
	}
	
}