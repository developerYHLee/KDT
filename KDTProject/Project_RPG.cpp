#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

#include "Equipment.h"
#include "Sword.h"
#include "Gun.h"
#include "Character.h"
#include "Enemy.h"

using namespace std;

Character* player;

void fight() {
	srand((unsigned int)time(NULL));

	int enemyHp = rand() % 20 - 50 + player->getFullHp();
	Enemy enemy(enemyHp);

	cout << "�� ����\n";
	enemy.printInfo();

	while (true) {
		cout << "[�÷��̾� ��]\n";
		cout << "� ������ �Ͻðڽ��ϱ�? (1 : ���� �ݱ�, 2 : ����, 3 : ���� ��Ȳ ����, �� �� : ����) : ";
		int order;
		cin >> order;

		if (order == 1) {
			int random = rand() % 2;

			player->grabItem(random);
		}
		else if (order == 2) {
			cout << "� ����� �����Ͻðڽ��ϱ�? (1 : Į, 2 : ��) : ";
			cin >> order;

			if (order == 1) enemy.hp -= player->swordAttack();
			else enemy.hp -= player->gunAttack();

			cout << "���� ���� ü�� : " << enemy.hp << endl << endl;

			if (enemy.hp <= 0) {
				cout << "���� óġ�Ͽ����ϴ�!\n\n";
				player->levelUp();
				break;
			}
		}
		else if (order == 3) {
			player->printEquipmentCount();
			continue;
		}
		else {
			cout << "�����ƽ��ϴ�!\n\n";
			break;
		}
		cout << "[�� ��]\n";
		order = rand() % 2 + 1;
		
		if (order == 1) {
			int random = rand() % 2;

			enemy.grabItem(random);
		}
		else {
			order = rand() % 2 + 1;

			if (order == 1) player->hp -= enemy.swordAttack();
			else player->hp -= enemy.gunAttack();

			cout << "�÷��̾��� ���� ü�� : " << player->hp << endl << endl;

			if (player->hp <= 0) break;
		}
	}
}

int main() {
	ifstream file1("ProjectRPG.txt");
	ofstream file2;

	vector<string> infos;

	cout << "ProjectRPG ���� ����\n";
	cout << "����� �Է��ϼ���. (1 : ���� ����, 2 : �ҷ�����) : ";
	int start;
	cin >> start;

	if (start == 2 && file1.is_open()) {
		string info;
		while (getline(file1, info)) infos.push_back(info);

		//���� ü��, �ִ� ü��, ����, Į ���Ƚ��, �� ���Ƚ��
		player = new Character(stoi(infos[0]), stoi(infos[1]), stoi(infos[2]), stoi(infos[3]), stoi(infos[4]));
		
		cout << "�ҷ�����\n\n";
	}
	else if (start == 2 && !file1.is_open()) {
		player = new Character();

		cout << "�ҷ����� ����\nĳ���� ����\n\n";
	}
	else {
		player = new Character();

		cout << "ĳ���� ����\n\n";
	}

	srand((unsigned int)time(NULL));

	while (true) {
		cout << "����� �Է��ϼ���. (1 : �� ���� ����, 2 : ���� �ο��, 3 : ü�� ����, �� �� : ���� ����) : ";
		int order;
		cin >> order;

		cout << endl;
		if (order == 1) player->printInfo();
		else if (order == 2) fight();
		else if (order == 3) {
			int random = rand() % 21 - 10;
			if (player->hp + random > player->getFullHp()) {
				player->hp = player->getFullHp();
				cout << "ü���� �ִ� ü�¿� �����߽��ϴ�.\n\n";
			}
			else {
				cout << random << "��ŭ ü�� ������ �ֽ��ϴ�.\n\n";
				player->hp += random;
			}
		}
		else break;

		if (player->hp <= 0) {
			cout << "�÷��̾ ����Ͽ����ϴ�!\nĳ���Ͱ� �ʱ�ȭ �� �� ������ ����˴ϴ�.\n\n";
			player = new Character();
			break;
		}
	}

	file2.open("ProjectRPG.txt");
	file2 << player->hp << '\n' << player->getFullHp() << '\n' << player->getLevel() << '\n' << player->getAttackCount_Sword() << '\n' << player->getAttackCount_Gun();

	cout << "���� ����\n";

	file1.close();
	file2.close();
}