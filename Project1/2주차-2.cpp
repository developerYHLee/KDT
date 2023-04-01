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
			cout << "캐릭터 정보" << endl << endl;
			for (int i = 0; i < infos.size(); i++) {
				cout << i + 1 << "번째 캐릭터 정보 출력" << endl;
				printInfo(infos[i][0], stoi(infos[i][1]), stoi(infos[i][2]), stoi(infos[i][3]));
				cout << endl;
			}

			int num;
			while (true) {
				cout << "선택할 캐릭터의 번호를 입력하세요 : ";
				int num;
				cin >> num;

				if (num > infos.size()) cout << "현재 존재하는 캐릭터 번호보다 큽니다.\n다시 입력하세요." << endl;
				else {
					id = num - 1;
					break;
				}
			}
			cout << endl;
		}
		else {
			cout << "파일 생성 오류!!" << endl;
			cout << "플레이어를 생성해주세요! 0을 눌러 종료하세요!" << endl << endl;
		}

		vector<string> info = infos[id];
		name = info[0];
		level = stoi(info[1]);
		item_num = stoi(info[2]);
		hp = stoi(info[3]);
	}
	class Game(string name, vector<vector<string>> infos) {
		cout << name << " 캐릭터가 생성 되었습니다." << endl << endl;
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
			cout << "어떤 동작을 실행하시겠습니까? (0 : 종료) : ";
			int num;
			cin >> num;
			
			if (num == 1) {
				cout << "새 이름을 입력해주세요 : ";
				string newName;
				cin >> newName;
				changeName(newName);
			}
			else if (num == 2) levelUp();
			else if (num == 3) pickItem();
			else if (num == 4) {
				if (item_num > 0) useItem();
				else cout << "아이템이 없습니다!" << endl;
			}
			else if (num == 5) printInfo(name, level, item_num, hp);
			else if (num == 6) {
				cout << "공격할 플레이어의 이름을 입력하세요. : ";
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

				if (!hasPlayer) cout << enemy << "은(는) 존재하지 않습니다!" << endl;
			}
			else {
				cout << "\n데이터 저장 시작" << endl;
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

				cout << "데이터 저장 완료" << endl << endl;
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
		cout << "이름이 변경되었습니다." << endl;
		cout << "new name : " << name << endl;
	}
	void levelUp() { 
		level++; 
		cout << "level up!" << endl;
		cout << "현재 레벨 : " << level << endl;
	}
	void pickItem() { 
		item_num++; 
		cout << "아이템을 얻었습니다!" << endl;
		cout << "현재 아이템 개수 : " << item_num << endl;
	}
	void useItem() { 
		item_num--; 
		cout << "아이템을 사용했습니다!" << endl;
		cout << "현재 아이템 개수 : " << item_num << endl;
	}
	string damage(string enemy, int enemyHp) {
		cout << enemy << "이(가) 공격 받았습니다!" << endl;
		enemyHp -= 10;
		cout << enemy << "의 현재 체력 : " << enemyHp << endl;
		return to_string(enemyHp);
	}
	void printInfo(string name, int level, int item_num, int hp) {
		cout << "플레이어 이름 : " << name << endl;
		cout << "레벨 : " << level << endl;
		cout << "아이템 개수 : " << item_num << endl;
		cout << "체력 : " << hp << endl;
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

	cout << "데이터 불러오기" << endl;
	if (readGame.is_open()) {
		cout << "데이터 불러오기 성공" << endl;
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
		cout << "데이터 불러오기 실패" << endl;
		cout << "게임 파일 생성" << endl << endl;
		writeGame.open("demoGame.txt");
	}

	readGame.close();
	writeGame.close();

	while (true) {
		char setPlayer;

		cout << "플레이어를 추가하겠습니까? (Y/N, 종료 : E) : ";
		cin >> setPlayer;
		cout << endl;

		if (setPlayer == 'N') {
			Game game(infos);
			infos = game.gameStart();
		}
		else if (setPlayer == 'Y') {
			cout << "새 캐릭터 이름을 입력하세요 : ";
			string name;
			cin >> name;
			Game game(name, infos);
			infos = game.gameStart();
		}
		else break;
	}
}