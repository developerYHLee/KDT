#pragma once

#ifndef __STARTGAME_H__
#define __STARTGAME_H__

#include <iostream>
#include <queue>
#include <stack>

#include "Board.h"

using std::cout;

class StartGame
{
private:
	bool** isWall;
	int _size, endRow, endCol;

	struct Path {
		int _row, _col, _vis;

		Path(int row, int col, int vis) {
			_row = row;
			_col = col;
			_vis = vis;
		}
	};

	int* move(int order, int row, int col);

public:
	StartGame(Board board);
	void printDir(int i);
	void bfs();
	void playGame();
};


#endif // ! __STARTGAME_H__


