#include "Board.h"

Board::Board(int size)
{
	_size = size;
	endRow = -1;
	endCol = -1;
	Initialize();
	Draw();
}

void Board::Initialize()
{
	srand((unsigned int)time(NULL));

	if (_size % 2 == 0) {
		cout << "홀수를 입력해주세요.\n\n";
		return;
	}

	isWall = new bool* [_size];
	for (int i = 0; i < _size; i++) {
		isWall[i] = new bool[_size];
		
		for (int j = 0; j < _size; j++) isWall[i][j] = false;
	}
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (i % 2 == 0 || j % 2 == 0) isWall[i][j] = true;
		}
	}

	for (int i = 0; i < _size; i++) {
		int count = 1;
		for (int j = 0; j < _size; j++) {
			if (i % 2 == 0 || j % 2 == 0) continue;
			if (i == _size - 2 && j == _size - 2) continue;
			
			if (i == _size - 2) {
				isWall[i][j + 1] = false;
				continue;
			}
			if (j == _size - 2) {
				isWall[i + 1][j] = false;
				continue;
			}


			int road = rand() % 2;
			if (road == 0) {
				isWall[i][j + 1] = false;
				count++;
			}
			else {
				int random = rand() % count;
				isWall[i + 1][j - random * 2] = false;
				count = 1;
			}
		}
	}

	while (true) {
		endRow = rand() % _size;
		endCol = rand() % _size;

		if (!isWall[endRow][endCol]) break;
	}
}

void Board::Draw()
{
	isWall[0][0] = false;
	isWall[0][1] = false;

	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (i == endRow && j == endCol) {
				cout << "□";
				continue;
			}
			if (isWall[i][j]) cout << "■";
			else cout << "  ";
		}
		cout << endl;
	}
	cout << "\n";
}

int Board::getSize() { return _size; }
bool** Board::getIsWall() { return isWall; }

int Board::getEndRow()
{
	return endRow;
}

int Board::getEndCol()
{
	return endCol;
}
