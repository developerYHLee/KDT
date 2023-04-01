#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream file("hello.txt");
	ofstream file2("bye.txt");

	//if (!file) cout << "파일 열기 실패\n";
	//if(file.fail()) cout << "파일 열기 실패\n";
	if(!file.is_open()) cout << "파일 열기 실패\n";
	else {
		cout << "파일 열기 성공\n";
	
		string l;
		while (getline(file, l)) file2 << l << endl;
	}

	file.close();

	
}