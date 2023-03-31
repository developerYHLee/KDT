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
	cout << "����, ���� ���̸� �Է��ϼ��� : ";
	cin >> rect.width >> rect.height;
	cout << "���� : " << rect.width * rect.height << endl << endl;

	string l;
	
	cout << "3���� ȸ���� ���� �̸��� ��й�ȣ�� ���������� �Է��ϼ���." << endl;
	ofstream file3;
	ifstream file4;
	
	/*
	file3.open("member.txt");
	if (!file3.fail()) {
		for (int i = 1; i <= 3; i++) {
			cout << i << "��° ȸ�� : ";
			getline(cin, l);
			file3 << l << endl;
		}
		
		cout << "----------ȸ�� ��� ���� �б�----------" << endl;
		
		file4.open("member.txt");
		while (getline(file4, l)) cout << l << endl;
	}
	else cout << "fail3 to open file" << endl;
	file3.close();
	file4.close();
	
	cout << endl;
	*/

	cout << "�̸��� �Է��ϼ��� : ";
	string name1;
	cin >> name1;
	cout << "����� �Է��ϼ��� : ";
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
		cout << "�α��� ����" << endl << endl;
		cout << "��ȭ��ȣ�� �Է��� �ּ��� : ";
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
	else cout << "�α��� ����" << endl << endl;
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