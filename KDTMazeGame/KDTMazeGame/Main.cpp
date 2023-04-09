#include <iostream>
#include <stack>
#include <queue>

#include "Board.h"

using namespace std;

bool** isWall;

struct Path {
	int _row, _col, _vis;

	Path(int row, int col, int vis) {
		_row = row;
		_col = col;
		_vis = vis;
	}
};

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

void bfs(int size) {
	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	bool** vis = new bool* [size];
	for (int i = 0; i < size; i++) {
		vis[i] = new bool[size];

		for (int j = 0; j < size; j++) vis[i][j] = false;
	}
	queue<Path> Q;
	Q.push(Path(0,0,0));
	vis[0][0] = true;
	
	while (!Q.empty()) {
		Path cur = Q.front();
		Q.pop();

		if (cur._row == size - 2 && cur._col == size - 1) {
			cout << "최단시도 : " << cur._vis << "\n\n";
			return ;
		}

		for (int i = 0; i < 4; i++) {
			int row = cur._row + dx[i];
			int col = cur._col + dy[i];

			if (row < 0 || col < 0 || row >= size || col >= size || vis[row][col] || isWall[row][col]) continue;

			Q.push(Path(row, col, cur._vis + 1));
			vis[row][col] = true;
		}
	}
}

void playGame(int size) {
	stack<Path> S;

	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	int curRow = 0, curCol = 0, vis = 0, count = 0;
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

		int* path;
		if (pathCount == 0) {
			cout << " )\n";
			cout << "길이 막혔으니 돌아가야합니다!\n";
			Path crossRoad = S.top();
			S.pop();

			curRow = crossRoad._row;
			curCol = crossRoad._col;
			vis = crossRoad._vis;

			cout << "갈림길로 돌아갔습니다.\n\n";
			continue;
		}
		else cout << " ) : ";

		int order;
		cin >> order;

		if (pathCount > 1) S.push(Path(curRow, curCol, order));

		path = move(order, curRow, curCol, size);
		curRow = path[0];
		curCol = path[1];
		vis = path[2];

		if (curRow == size - 2 && curCol == size - 1) {
			cout << "미로를 빠져나왔습니다!\n";
			break;
		}

		count++;
	}

	cout << "미로를 탈출하는데 " << count << "번 시도했습니다.\n\n";
}

int main() {
	cout << "미로의 크기를 입력하세요. (홀수만 입력) : ";
	int size;
	cin >> size;

	Board board(size);
	cout << "\n";
	
	isWall = board.getIsWall();
	
	while (true) {
		cout << "명령을 입력하세요. (1 : 미로 게임 시작, 2 : 최단거리 확인, 0 : 종료) : ";
		int order;
		cin >> order;

		if (order == 1) playGame(size);
		else if (order == 2) bfs(size);
		else if (order == 0) break;

	}

	cout << "미로 게임 종료\n";
}