#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream file("hello.txt");

	ofstream file2;
	file2.open("bye.txt"); //std::ios::app를 매개변수에 추가하면 데이터 이어쓰기 가능

	file2 << "새로운 데이터 쓰기!" << endl;

	if (!file) cout << "파일 열기 실패\n";
	if(file.fail()) cout << "파일 열기 실패\n";
	if(!file.is_open()) cout << "파일 열기 실패\n";
	else {
		cout << "파일 열기 성공\n";
	
		string l;
		while (getline(file, l)) file2 << l << endl;
	}

	file.close();
	file2.close();
}