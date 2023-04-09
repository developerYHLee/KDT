#include <iostream>
#include "Board.h"
#include "StartGame.h"

using namespace std;

int main() {
	cout << "미로의 크기를 입력하세요. (홀수만 입력) : ";
	int size;
	cin >> size;

	Board board(size);

	while (true) {

		cout << "명령을 입력하세요. (1 : 미로 게임 시작, 2 : 최단거리 확인, 3 : 미로 확인, 0 : 종료) : ";
		int order;
		cin >> order;

		StartGame startGame(board);
		
		if (order == 1) startGame.playGame();
		else if (order == 2) startGame.bfs();
		else if (order == 3) board.Draw();
		else if (order == 0) break;
	}

	cout << "미로 게임 종료\n";
}