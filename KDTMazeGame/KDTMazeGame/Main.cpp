#include <iostream>
#include <stack>

#include "Board.h"

using namespace std;

bool** isWall;

void printDir(int i) {
	if (i == 0) cout << " 상 : 0";
	else if (i == 1) cout << " 하 : 1";
	else if (i == 2) cout << " 좌 : 2";
	else cout << " 우 : 3";
}

int* move(int order, int row, int col, int size) {
	int* res = new int[3];
	int vis = 0;

	res[0] = row;
	res[1] = col;
	res[2] = vis;

	if (order == 0) {
		row--;
		if (row < 0 || isWall[row][col]) cout << "위로 이동할 수 없습니다. 다시 선택하세요.\n\n";
		else {
			cout << "위로 이동!\n\n";
			res[0] = row;
			res[2] = 1;
		}
	}
	else if (order == 1) {
		row++;
		if (row >= size || isWall[row][col]) cout << "아래로 이동할 수 없습니다. 다시 선택하세요.\n\n";
		else {
			cout << "아래로 이동!\n\n";
			res[0] = row;
			res[2] = 0;
		}
	}
	else if (order == 2) {
		col--;
		if (col < 0 || isWall[row][col]) cout << "왼쪽으로 이동할 수 없습니다. 다시 선택하세요.\n\n";
		else {
			cout << "왼쪽로 이동!\n\n";
			res[1] = col;
			res[2] = 3;
		}
	}
	else {
		col++;
		if (col >= size || isWall[row][col]) cout << "오른쪽으로 이동할 수 없습니다. 다시 선택하세요.\n\n";
		else {
			cout << "오른쪽로 이동!\n\n";
			res[1] = col;
			res[2] = 2;
		}
	}

	return res;
}

int main() {
	cout << "미로의 크기를 입력하세요. (홀수만 입력) : ";
	int size;
	cin >> size;

	Board board(size);
	cout << "\n\n";
	
	isWall = board.getIsWall();
	stack<pair<int, int>> S;
	
	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };
	
	int curRow = 0, curCol = 0, vis = 0;
	while (true) {
		cout << "이동 가능한 방향(";

		int pathCount = 0;
		for (int i = 0; i < 4; i++) {
			int row = curRow + dx[i];
			int col = curCol + dy[i];

			if (row < 0 || col < 0 || row >= size || col >= size || isWall[row][col]) continue;
			
			printDir(i);
			if (vis == i) cout << "(방금 지나온 길)";
			else pathCount++;
		}
		cout << " ) : ";
		if (pathCount == 0) {
			cout << "돌아가야합니다!\n\n";

		}
		
		int order;
		cin >> order;

		int *path = move(order, curRow, curCol, size);
		

		if (curRow == size - 2 && curCol == size - 1) {
			cout << "미로를 빠져나왔습니다!\n";
			break;
		}
	}
	
}