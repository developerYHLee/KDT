#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string);

class Game {
	string name;
	int level, item_num, hp, id;
	vector<vector<string>> infos;

public :
	class Game(vector<vector<string>> infos) {
		string s;
		this->infos = infos;

		if (infos.size() > 0) {
			cout << "ĳ���� ����" << endl << endl;
			for (int i = 0; i < infos.size(); i++) {
				cout << i + 1 << "��° ĳ���� ���� ���" << endl;
				printInfo(infos[i][0], stoi(infos[i][1]), stoi(infos[i][2]), stoi(infos[i][3]));
				cout << endl;
			}

			int num;
			while (true) {
				cout << "������ ĳ������ ��ȣ�� �Է��ϼ��� : ";
				int num;
				cin >> num;

				if (num > infos.size()) cout << "���� �����ϴ� ĳ���� ��ȣ���� Ů�ϴ�.\n�ٽ� �Է��ϼ���." << endl;
				else {
					id = num - 1;
					break;
				}
			}
			cout << endl;
		}
		else {
			cout << "���� ���� ����!!" << endl;
			cout << "�÷��̾ �������ּ���! 0�� ���� �����ϼ���!" << endl << endl;
		}

		vector<string> info = infos[id];
		name = info[0];
		level = stoi(info[1]);
		item_num = stoi(info[2]);
		hp = stoi(info[3]);
	}
	class Game(string name, vector<vector<string>> infos) {
		cout << name << " ĳ���Ͱ� ���� �Ǿ����ϴ�." << endl << endl;
		this->name = name;
		level = 0;
		item_num = 0;
		hp = 100;
		id = infos.size();
		this->infos = infos;
		
		vector<string> info;
		info.push_back(this->name);
		info.push_back(to_string(this->level));
		info.push_back(to_string(this->item_num));
		info.push_back(to_string(this->hp));
		this->infos.push_back(info);
	}

	vector<vector<string>> gameStart() {
		while(true) {
			cout << "� ������ �����Ͻðڽ��ϱ�? (0 : ����) : ";
			int num;
			cin >> num;
			
			if (num == 1) {
				cout << "�� �̸��� �Է����ּ��� : ";
				string newName;
				cin >> newName;
				changeName(newName);
			}
			else if (num == 2) levelUp();
			else if (num == 3) pickItem();
			else if (num == 4) {
				if (item_num > 0) useItem();
				else cout << "�������� �����ϴ�!" << endl;
			}
			else if (num == 5) printInfo(name, level, item_num, hp);
			else if (num == 6) {
				cout << "������ �÷��̾��� �̸��� �Է��ϼ���. : ";
				string enemy;
				cin >> enemy;
				bool hasPlayer = false;

				for (int i = 0; i < infos.size(); i++) {
					if (infos[i][0].compare(enemy) == 0) {
						hasPlayer = true;
						infos[i][3] = damage(infos[i][0], stoi(infos[i][3]));
						break;
					}
				}

				if (!hasPlayer) cout << enemy << "��(��) �������� �ʽ��ϴ�!" << endl;
			}
			else {
				cout << "\n������ ���� ����" << endl;
				ofstream writeGame("demoGame.txt");

				infos[id][0] = name;
				infos[id][1] = to_string(level);
				infos[id][2] = to_string(item_num);
				infos[id][3] = to_string(hp);

				if (infos.size() > 0) {
					for (vector<string> info : infos) {
						for (string str : info) writeGame << str << ' ';
						writeGame << endl;
					}
				}

				cout << "������ ���� �Ϸ�" << endl << endl;
				break;
			}
			cout << endl;
		}

		return infos;
	}

private:
	void changeName(string name) { 
		cout << "old name : " << this->name << endl;
		this->name = name; 
		cout << "�̸��� ����Ǿ����ϴ�." << endl;
		cout << "new name : " << name << endl;
	}
	void levelUp() { 
		level++; 
		cout << "level up!" << endl;
		cout << "���� ���� : " << level << endl;
	}
	void pickItem() { 
		item_num++; 
		cout << "�������� ������ϴ�!" << endl;
		cout << "���� ������ ���� : " << item_num << endl;
	}
	void useItem() { 
		item_num--; 
		cout << "�������� ����߽��ϴ�!" << endl;
		cout << "���� ������ ���� : " << item_num << endl;
	}
	string damage(string enemy, int enemyHp) {
		cout << enemy << "��(��) ���� �޾ҽ��ϴ�!" << endl;
		enemyHp -= 10;
		cout << enemy << "�� ���� ü�� : " << enemyHp << endl;
		return to_string(enemyHp);
	}
	void printInfo(string name, int level, int item_num, int hp) {
		cout << "�÷��̾� �̸� : " << name << endl;
		cout << "���� : " << level << endl;
		cout << "������ ���� : " << item_num << endl;
		cout << "ü�� : " << hp << endl;
	}
};

vector<string> split(string str) {
	string s;
	vector<string> res;
	stringstream stream(str);
	while (stream >> s) res.push_back(s);

	return res;
}

int main() {
	ifstream readGame("demoGame.txt");
	ofstream writeGame;
	vector<vector<string>> infos;

	cout << "������ �ҷ�����" << endl;
	if (readGame.is_open()) {
		cout << "������ �ҷ����� ����" << endl;
		string data;
		while (getline(readGame, data)) {
			vector<string> info = split(data);
			infos.push_back(info);
		}
		writeGame.open("demoGame.txt");

		if (infos.size() > 0) {
			for (vector<string> info : infos) {
				for (string str : info) writeGame << str << ' ';
				writeGame << endl;
			}
		}
	}
	else {
		cout << "������ �ҷ����� ����" << endl;
		cout << "���� ���� ����" << endl << endl;
		writeGame.open("demoGame.txt");
	}

	readGame.close();
	writeGame.close();

	while (true) {
		char setPlayer;

		cout << "�÷��̾ �߰��ϰڽ��ϱ�? (Y/N, ���� : E) : ";
		cin >> setPlayer;
		cout << endl;

		if (setPlayer == 'N') {
			Game game(infos);
			infos = game.gameStart();
		}
		else if (setPlayer == 'Y') {
			cout << "�� ĳ���� �̸��� �Է��ϼ��� : ";
			string name;
			cin >> name;
			Game game(name, infos);
			infos = game.gameStart();
		}
		else break;
	}
}