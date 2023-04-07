#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Equipment {
public:
	int hasCount, damage;

	Equipment(int hasCount, int damage) {
		this->hasCount = hasCount;
		this->damage = damage;
	}

	virtual int attack() = 0;
	virtual void grabEquipment() = 0;

	int attackCount() { return hasCount; }
};

class Sword : public Equipment {
public:
	Sword() : Equipment(3, 5) {

	}

	Sword(int hasCount) : Equipment(hasCount, 5) {

	}

	int attack() {
		if (hasCount <= 0) {
			cout << "공격 기회가 없습니다!\n\n";
			return 0;
		}

		hasCount--;
		cout << "찌르기\n\n";
		return damage;
	}

	void grabEquipment() { 
		cout << "칼을 주웠습니다.\n\n";
		hasCount += 3; 
	}
};

class Gun : public Equipment {
public:
	Gun() : Equipment(1, 10) {

	}

	Gun(int hasCount) : Equipment(hasCount, 10) {

	}

	int attack() {
		if (hasCount <= 0) {
			cout << "공격 기회가 없습니다!\n\n";
			return 0;
		}

		hasCount--;
		cout << "총쏘기\n\n";
		return damage;
	}

	void grabEquipment() { 
		cout << "총을 주웠습니다.\n\n";
		hasCount++; 
	}

};

class Character {
private:
	int m_hp, _level, _fullHp;
	
	void resetCharater() {
		m_hp = 100;
		_fullHp = 100;
		_level = 1;
		_sword = new Sword();
		_gun = new Gun(0);
	}
public:
	Sword* _sword;
	Gun* _gun;

	int getHp() { return m_hp; }
	void setHp(int _hp) { this->m_hp = _hp; }

	__declspec(property(get = getHp, put = setHp)) int hp;
	
	Character() {
		resetCharater();
	}

	Character(int hp, int fullHp, int level, int countSword, int countGun) {
		this->m_hp = hp;
		this->_fullHp = fullHp;
		this->_level = level;
		_sword = new Sword(countSword);
		_gun = new Gun(countGun);
	}
	
	int swordAttack() { return _sword->attack(); }
	int gunAttack() { return _gun->attack(); }
	void grabItem(int item) {
		if (item == 0) _sword->grabEquipment();
		else _gun->grabEquipment();
	}
	void levelUp() {
		_fullHp *= 1.2;
		m_hp = _fullHp;
	}

	void printInfo() {
		cout << "최대 체력 : " << _fullHp << endl;
		cout << "현재 체력 : " << m_hp << endl;
		cout << "레벨 : " << _level << endl;
		cout << "칼 사용 가능 횟수 : " << _sword->attackCount() << endl;
		cout << "총 사용 가능 횟수 : " << _gun->attackCount() << endl << endl;
	}

	void printEquipmentCount() {
		cout << "칼 사용 가능 횟수 : " << _sword->attackCount() << endl;
		cout << "총 사용 가능 횟수 : " << _gun->attackCount() << endl << endl;
	}

	int getLevel() { return _level; }
	int getFullHp() { return _fullHp; }
	int getAttackCount_Sword() { return _sword->attackCount(); }
	int getAttackCount_Gun() { return _gun->attackCount(); }
};

class Enemy : public Character {
public:
	Enemy(int hp) : Character(hp, hp, 0, 5, 2) {

	}

	int computerTurn() {
		srand((unsigned int)time(NULL));

		//0 : 칼 줍기, 1 : 총 줍기, 2 : 칼 공격, 3 : 총 공격
		int random = rand() % 4;

		if (random == 0) {
			_sword->grabEquipment();
			return 0;
		}
		else if (random == 1) {
			_gun->grabEquipment();
			return 0;
		}
		else if (random == 2) { return _sword->attack(); }
		else { return _gun->attack(); }
	}
};

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
			if (player->hp + random > player->getFullHp()) cout << "최대 체력을 넘을 수 없습니다.\n\n";
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