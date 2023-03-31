#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Rectangle {
	float width, height;
};

vector<string> split1(string str, char Delimiter) {
	istringstream iss(str);
	string buffer;

	vector<string> result;

	while (getline(iss, buffer, Delimiter)) result.push_back(buffer);

	return result;
}

vector<string> split2(string str) {
	string s;
	vector<string> result;
	stringstream stream(str);
	while (stream >> s) result.push_back(s);
	
	return result;
}

int main() {
	Rectangle rect;
	cout << "가로, 세로 길이를 입력하세요 : ";
	cin >> rect.width >> rect.height;
	cout << "넓이 : " << rect.width * rect.height << endl << endl;

	string l;
	
	cout << "3명의 회원에 대한 이름과 비밀번호를 순차적으로 입력하세요." << endl;
	ofstream file3;
	ifstream file4;
	
	/*
	file3.open("member.txt");
	if (!file3.fail()) {
		for (int i = 1; i <= 3; i++) {
			cout << i << "번째 회원 : ";
			getline(cin, l);
			file3 << l << endl;
		}
		
		cout << "----------회원 명부 파일 읽기----------" << endl;
		
		file4.open("member.txt");
		while (getline(file4, l)) cout << l << endl;
	}
	else cout << "fail3 to open file" << endl;
	file3.close();
	file4.close();
	
	cout << endl;
	*/

	cout << "이름을 입력하세요 : ";
	string name1;
	cin >> name1;
	cout << "비번을 입력하세요 : ";
	int password1;
	cin >> password1;
	
	file4.open("member.txt");
	bool login = false;
	if (!file4.fail()) {
		while (getline(file4, l)) {
			vector<string> info = split1(l, ' ');

			if (info[0].compare(name1) == 0 && stoi(info[1]) == password1) {
				login = true;
				break;
			}
		}
	}
	else cout << "fail4 to open file" << endl;

	if (login) {
		cout << "로그인 성공" << endl << endl;
		cout << "전화번호를 입력해 주세요 : ";
		cin >> l;
		vector<string> infos;

		ifstream file6("member_tel.txt");
		string info;
		if (file6.is_open()) {
			while (getline(file6, info)) infos.push_back(info);
		}

		ofstream file5("member_tel.txt");
		for (string info : infos) file5 << info << endl;
		file5 << name1 << ' ' << l << endl;
	}
	else cout << "로그인 실패" << endl << endl;
	file4.close();

	ifstream file;
	file.open("hello.txt");
	vector<string> line;
	if (file.is_open()) {
		while (getline(file, l)) line.push_back(l);
	}
	else cout << "fail" << endl << endl;
	file.close();

	ofstream file2("output.txt");
	if (!file2.fail()) {
		for (int i = line.size() - 1; i >= 0; i--) file2 << line[i] << endl;
	}
	else cout << "fail2 to open file" << endl;
	file2.close();
}