#include <iostream>

using namespace std;

class Student {
	string name, school;
	int age, id;
public:
	class Student(string name, string school, int age, int id) {
		this->name = name;
		this->school = school;
		this->age = age;
		this->id = id;
	}
	void lunch() {
		cout << "점심은 학식" << endl;
	}
	void printInfo() {
		cout << "이름 : " << name << "\n학교 : " << school << "\n나이 : " << age << "\n학번 : " << id << endl;
	}
};

class Kim : Student {
public:
	class Kim(string name, string school, int age, int id) : Student(name, school, age, id) {

	}

	void lunch() {
		cout << "점심은 김가네 김밥" << endl;
	}
	void printInfo() {
		Student::printInfo();
	}
};

class Baek : Student {
public:
	class Baek(string name, string school, int age, int id) : Student(name, school, age, id) {

	}

	void lunch() {
		cout << "점심은 백종원 피자" << endl;
	}
	void printInfo() {
		Student::printInfo();
	}
};

int main() {
	Student s("학생", "학생 부모클래스", 20, 202301001);
	s.printInfo();
	s.lunch();
	cout << endl;

	Kim kim("김안녕", "포스코 학교", 21, 202203021);
	kim.printInfo();
	kim.lunch();
	cout << endl;

	Baek baek("백잘가", "코딩온 학교", 22, 202105156);
	baek.printInfo();
	baek.lunch();
	cout << endl;
}