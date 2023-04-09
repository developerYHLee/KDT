#include "StartGame.h"

StartGame::StartGame(Board board)
{
	isWall = board.getIsWall();
	_size = board.getSize();
	endRow = board.getEndRow();
	endCol = board.getEndCol();
}

int* StartGame::move(int order, int row, int col) {
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
		if (row >= _size || isWall[row][col]) cout << "�Ʒ��� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
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
		if (col >= _size || isWall[row][col]) cout << "���������� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "�����ʷ� �̵�!\n\n";
			res[1] = col;
			res[2] = 2;
		}
	}

	return res;
}

void StartGame::printDir(int i) {
	if (i == 0) cout << " �� : 0";
	else if (i == 1) cout << " �� : 1";
	else if (i == 2) cout << " �� : 2";
	else cout << " �� : 3";
}

void StartGame::bfs() {
	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	bool** vis = new bool* [_size];
	for (int i = 0; i < _size; i++) {
		vis[i] = new bool[_size];

		for (int j = 0; j < _size; j++) vis[i][j] = false;
	}
	queue<Path> Q;
	Q.push(Path(0, 0, 0));
	vis[0][0] = true;

	while (!Q.empty()) {
		Path cur = Q.front();
		Q.pop();

		if (cur._row == endRow && cur._col == endCol) {
			cout << "�ִܽõ� : " << cur._vis << "\n\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int row = cur._row + dx[i];
			int col = cur._col + dy[i];

			if (row < 0 || col < 0 || row >= _size || col >= _size || vis[row][col] || isWall[row][col]) continue;

			Q.push(Path(row, col, cur._vis + 1));
			vis[row][col] = true;
		}
	}
}

void StartGame::playGame()
{
	stack<Path> S;

	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	int curRow = 0, curCol = 0, vis = 0, count = 0;
	while (true) {
		cout << "�̵� ������ ����(";

		int pathCount = 0;
		for (int i = 0; i < 4; i++) {
			int row = curRow + dx[i];
			int col = curCol + dy[i];

			if (row < 0 || col < 0 || row >= _size || col >= _size || isWall[row][col]) continue;

			printDir(i);
			if (vis == i) cout << "(��� ������ ��)";
			else pathCount++;
		}

		int* path;
		if (pathCount == 0) {
			cout << " )\n";
			cout << "���� �������� ���ư����մϴ�!\n";
			Path crossRoad = S.top();
			S.pop();

			curRow = crossRoad._row;
			curCol = crossRoad._col;
			vis = crossRoad._vis;

			cout << "������� ���ư����ϴ�.\n\n";

			continue;
		}
		else cout << " ) : ";

		int order;
		cin >> order;

		if (pathCount > 1) S.push(Path(curRow, curCol, order));

		path = move(order, curRow, curCol);
		curRow = path[0];
		curCol = path[1];
		vis = path[2];

		count++;
		if (curRow == endRow && curCol == endCol) {
			cout << "�̷θ� �������Խ��ϴ�!\n";
			break;
		}
	}

	cout << "�̷θ� Ż���ϴµ� " << count << "�� �õ��߽��ϴ�.\n\n";
}