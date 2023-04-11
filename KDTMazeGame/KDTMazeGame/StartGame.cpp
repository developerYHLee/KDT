#include "StartGame.h"

StartGame::StartGame(Board *board)
{
	isWall = board->getIsWall();
	_size = board->getSize();
	endRow = board->getEndRow();
	endCol = board->getEndCol();
}

int* StartGame::move(int order, int row, int col) {
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
		if (row >= _size || isWall[row][col]) cout << "아래로 이동할 수 없습니다. 다시 선택하세요.\n\n";
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
			cout << "왼쪽으로 이동!\n\n";
			res[1] = col;
			res[2] = 3;
		}
	}
	else {
		col++;
		if (col >= _size || isWall[row][col]) cout << "오른쪽으로 이동할 수 없습니다. 다시 선택하세요.\n\n";
		else {
			cout << "오른쪽으로 이동!\n\n";
			res[1] = col;
			res[2] = 2;
		}
	}

	return res;
}

void StartGame::printDir(int i) {
	if (i == 0) cout << " ↑ : 0";
	else if (i == 1) cout << " ↓ : 1";
	else if (i == 2) cout << " ← : 2";
	else cout << " → : 3 ";
}

void StartGame::playGame()
{
	cout << "\n미로 찾기 시작!\n위치 알림 찬스가 한번 있습니다.\n현재 위치를 알고 싶으면 9를 입력하세요.\n\n";
	Path* P = new Path(0, 0, 0);

	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	int curRow = 0, curCol = 0, vis = 0, count = 0, getLocate = 1;
	while (true) {
		cout << "이동 가능한 방향(";

		int pathCount = 0;
		for (int i = 0; i < 4; i++) {
			int row = curRow + dx[i];
			int col = curCol + dy[i];

			if (row < 0 || col < 0 || row >= _size || col >= _size || isWall[row][col]) continue;

			printDir(i);
			if (vis == i) cout << "(방금 지나온 길)";
			else pathCount++;
		}

		int* path;
		if (pathCount == 0) {
			if (curRow == 0 && curCol == 0) {
				cout << ") :\n시작 지점입니다.\n\n";
				vis = 0;
				continue;
			}

			cout << ")\n";
			cout << "길이 막혔으니 돌아가야합니다!\n";

			curRow = P->_row;
			curCol = P->_col;
			vis = P->_vis;

			cout << "갈림길로 돌아갔습니다.\n\n";

			continue;
		}
		else cout << ") : ";

		int order;
		cin >> order;

		if (order == 9) {
			if (getLocate == 0) {
				cout << "위치 알림 찬스를 이미 사용했습니다.\n\n";
				continue;
			}

			getLocate--;
			cout << "현재 위치 : " << curRow << "행 " << curCol << "열\n\n";
			continue;
		}

		if (pathCount > 1) P = new Path(curRow, curCol, order);

		path = move(order, curRow, curCol);
		curRow = path[0];
		curCol = path[1];
		vis = path[2];

		count++;
		if (curRow == endRow && curCol == endCol) {
			cout << "미로를 빠져나왔습니다!\n";
			break;
		}

		delete path;
	}

	cout << "미로를 탈출하는데 " << count << "번 시도했습니다.\n\n";

	delete P;
}