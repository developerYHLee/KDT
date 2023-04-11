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
			cout << "�������� �̵�!\n\n";
			res[1] = col;
			res[2] = 3;
		}
	}
	else {
		col++;
		if (col >= _size || isWall[row][col]) cout << "���������� �̵��� �� �����ϴ�. �ٽ� �����ϼ���.\n\n";
		else {
			cout << "���������� �̵�!\n\n";
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
	else cout << " �� : 3 ";
}

void StartGame::playGame()
{
	cout << "\n�̷� ã�� ����!\n��ġ �˸� ������ �ѹ� �ֽ��ϴ�.\n���� ��ġ�� �˰� ������ 9�� �Է��ϼ���.\n\n";
	Path* P = new Path(0, 0, 0);

	int dx[] = { -1, 1, 0, 0 }, dy[] = { 0,0,-1,1 };

	int curRow = 0, curCol = 0, vis = 0, count = 0, getLocate = 1;
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
			if (curRow == 0 && curCol == 0) {
				cout << ") :\n���� �����Դϴ�.\n\n";
				vis = 0;
				continue;
			}

			cout << ")\n";
			cout << "���� �������� ���ư����մϴ�!\n";

			curRow = P->_row;
			curCol = P->_col;
			vis = P->_vis;

			cout << "������� ���ư����ϴ�.\n\n";

			continue;
		}
		else cout << ") : ";

		int order;
		cin >> order;

		if (order == 9) {
			if (getLocate == 0) {
				cout << "��ġ �˸� ������ �̹� ����߽��ϴ�.\n\n";
				continue;
			}

			getLocate--;
			cout << "���� ��ġ : " << curRow << "�� " << curCol << "��\n\n";
			continue;
		}

		if (pathCount > 1) P = new Path(curRow, curCol, order);

		path = move(order, curRow, curCol);
		curRow = path[0];
		curCol = path[1];
		vis = path[2];

		count++;
		if (curRow == endRow && curCol == endCol) {
			cout << "�̷θ� �������Խ��ϴ�!\n";
			break;
		}

		delete path;
	}

	cout << "�̷θ� Ż���ϴµ� " << count << "�� �õ��߽��ϴ�.\n\n";

	delete P;
}