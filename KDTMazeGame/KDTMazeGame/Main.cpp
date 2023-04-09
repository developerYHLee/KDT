#include <iostream>
#include "Board.h"
#include "StartGame.h"

using namespace std;

int main() {
	cout << "�̷��� ũ�⸦ �Է��ϼ���. (Ȧ���� �Է�) : ";
	int size;
	cin >> size;

	Board board(size);
	cout << "\n";
	
	StartGame startGame(board);

	while (true) {
		cout << "����� �Է��ϼ���. (1 : �̷� ���� ����, 2 : �ִܰŸ� Ȯ��, 0 : ����) : ";
		int order;
		cin >> order;

		if (order == 1) startGame.playGame();
		else if (order == 2) startGame.bfs();
		else if (order == 0) break;
	}

	cout << "�̷� ���� ����\n";
}