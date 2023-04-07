#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str) {
	string s;
	vector<string> res;
	stringstream stream(str);
	while (stream >> s) res.push_back(s);

	return res;
}

class Character {
private:
	int hp, level, countEquip;
	Equipment* equipment[10]; //최대 개수 10개
	
	void resetCharater() {
		hp = 100;
		level = 1;
		countEquip = 0;
		equipment[countEquip] = new Sword();
	}
public:
	Character() {
		resetCharater();
	}

	Character(int hp, int level) {
		resetCharater();
	}
};

class Equipment {

};

class Sword : public Equipment {

};

class Gun : public Equipment {

};

int main() {
	ifstream file1("ProjectRPG");
	ofstream file2;

	vector<string> infos;
	Character player;
	
	if (file1.is_open()) {
		string info;
		for (int i = 0; getline(file1, info); i++) infos.push_back(info);
		
		file2.open("ProjectRPG");
		for (string s : infos) file2 << s;
	}
	else {
		file2.open("ProjectRPG");
	}
}