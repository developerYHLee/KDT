#pragma once
#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Board
{
private:
	int _size;
	bool** isWall;
public:
	Board(int size);

	void Initialize();
	void Draw();
	int getSize();
	bool** getIsWall();
};

#endif // !__BOARD_H__