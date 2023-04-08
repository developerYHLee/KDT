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

	cout << "적 정보\n";
	enemy.printInfo();

	while (true) {
		cout << "[플레이어 턴]\n";
		cout << "어떤 동작을 하시겠습니까? (1 : 무기 줍기, 2 : 공격, 3 : 무기 현황 보기, 그 외 : 도망) : ";
		int order;
		cin >> order;

		if (order == 1) {
			int random = rand() % 2;

			player->grabItem(random);
		}
		else if (order == 2) {
			cout << "어떤 무기로 공격하시겠습니까? (1 : 칼, 2 : 총) : ";
			cin >> order;

			if (order == 1) enemy.hp -= player->swordAttack();
			else enemy.hp -= player->gunAttack();

			cout << "적의 현재 체력 : " << enemy.hp << endl << endl;

			if (enemy.hp <= 0) {
				cout << "적을 처치하였습니다!\n\n";
				player->levelUp();
				break;
			}
		}
		else if (order == 3) {
			player->printEquipmentCount();
			continue;
		}
		else {
			cout << "도망쳤습니다!\n\n";
			break;
		}
		cout << "[적 턴]\n";
		order = rand() % 2 + 1;
		
		if (order == 1) {
			int random = rand() % 2;

			enemy.grabItem(random);
		}
		else {
			order = rand() % 2 + 1;

			if (order == 1) player->hp -= enemy.swordAttack();
			else player->hp -= enemy.gunAttack();

			cout << "플레이어의 현재 체력 : " << player->hp << endl << endl;

			if (player->hp <= 0) break;
		}
	}
}

int main() {
	ifstream file1("ProjectRPG.txt");
	ofstream file2;

	vector<string> infos;

	cout << "ProjectRPG 게임 시작\n";
	cout << "명령을 입력하세요. (1 : 새로 시작, 2 : 불러오기) : ";
	int start;
	cin >> start;

	if (start == 2 && file1.is_open()) {
		string info;
		while (getline(file1, info)) infos.push_back(info);

		//현재 체력, 최대 체력, 레벨, 칼 사용횟수, 총 사용횟수
		player = new Character(stoi(infos[0]), stoi(infos[1]), stoi(infos[2]), stoi(infos[3]), stoi(infos[4]));
		
		cout << "불러오기\n\n";
	}
	else if (start == 2 && !file1.is_open()) {
		player = new Character();

		cout << "불러오기 실패\n캐릭터 생성\n\n";
	}
	else {
		player = new Character();

		cout << "캐릭터 생성\n\n";
	}

	srand((unsigned int)time(NULL));

	while (true) {
		cout << "명령을 입력하세요. (1 : 내 정보 보기, 2 : 적과 싸우기, 3 : 체력 도박, 그 외 : 게임 종료) : ";
		int order;
		cin >> order;

		cout << endl;
		if (order == 1) player->printInfo();
		else if (order == 2) fight();
		else if (order == 3) {
			int random = rand() % 21 - 10;
			if (player->hp + random > player->getFullHp()) {
				player->hp = player->getFullHp();
				cout << "체력이 최대 체력에 도달했습니다.\n\n";
			}
			else {
				cout << random << "만큼 체력 변동이 있습니다.\n\n";
				player->hp += random;
			}
		}
		else break;

		if (player->hp <= 0) {
			cout << "플레이어가 사망하였습니다!\n캐릭터가 초기화 된 후 게임이 종료됩니다.\n\n";
			player = new Character();
			break;
		}
	}

	file2.open("ProjectRPG.txt");
	file2 << player->hp << '\n' << player->getFullHp() << '\n' << player->getLevel() << '\n' << player->getAttackCount_Sword() << '\n' << player->getAttackCount_Gun();

	cout << "게임 종료\n";

	file1.close();
	file2.close();
}