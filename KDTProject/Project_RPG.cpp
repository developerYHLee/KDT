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
			cout << "���� ��ȸ�� �����ϴ�!\n\n";
			return 0;
		}

		hasCount--;
		cout << "���\n\n";
		return damage;
	}

	void grabEquipment() { 
		cout << "Į�� �ֿ����ϴ�.\n\n";
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
			cout << "���� ��ȸ�� �����ϴ�!\n\n";
			return 0;
		}

		hasCount--;
		cout << "�ѽ��\n\n";
		return damage;
	}

	void grabEquipment() { 
		cout << "���� �ֿ����ϴ�.\n\n";
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
		cout << "�ִ� ü�� : " << _fullHp << endl;
		cout << "���� ü�� : " << m_hp << endl;
		cout << "���� : " << _level << endl;
		cout << "Į ��� ���� Ƚ�� : " << _sword->attackCount() << endl;
		cout << "�� ��� ���� Ƚ�� : " << _gun->attackCount() << endl << endl;
	}

	void printEquipmentCount() {
		cout << "Į ��� ���� Ƚ�� : " << _sword->attackCount() << endl;
		cout << "�� ��� ���� Ƚ�� : " << _gun->attackCount() << endl << endl;
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

		//0 : Į �ݱ�, 1 : �� �ݱ�, 2 : Į ����, 3 : �� ����
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
			if (player->hp + random > player->getFullHp()) cout << "�ִ� ü���� ���� �� �����ϴ�.\n\n";
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