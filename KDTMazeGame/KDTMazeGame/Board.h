#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

class Board
{
private:
	struct Path {
		int _row, _col, _vis;

		Path(int row, int col, int vis) {
			_row = row;
			_col = col;
			_vis = vis;
		}
	};

	int _size, endRow, endCol;
	bool** isWall;

	void setStart();
public:
	Board(int size);

	void Initialize();
	void Draw();
	int getSize();
	bool** getIsWall();
	int getEndRow();
	int getEndCol();
	int bfs(bool printDis);
};

#endif // !__BOARD_H__