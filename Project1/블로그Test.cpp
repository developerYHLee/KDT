#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream file("hello.txt");
	ofstream file2("bye.txt");

	//if (!file) cout << "���� ���� ����\n";
	//if(file.fail()) cout << "���� ���� ����\n";
	if(!file.is_open()) cout << "���� ���� ����\n";
	else {
		cout << "���� ���� ����\n";
	
		string l;
		while (getline(file, l)) file2 << l << endl;
	}

	file.close();

	
}