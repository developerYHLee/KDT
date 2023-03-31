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
		cout << "������ �н�" << endl;
	}
	void printInfo() {
		cout << "�̸� : " << name << "\n�б� : " << school << "\n���� : " << age << "\n�й� : " << id << endl;
	}
};

class Kim : Student {
public:
	class Kim(string name, string school, int age, int id) : Student(name, school, age, id) {

	}

	void lunch() {
		cout << "������ �谡�� ���" << endl;
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
		cout << "������ ������ ����" << endl;
	}
	void printInfo() {
		Student::printInfo();
	}
};

int main() {
	Student s("�л�", "�л� �θ�Ŭ����", 20, 202301001);
	s.printInfo();
	s.lunch();
	cout << endl;

	Kim kim("��ȳ�", "������ �б�", 21, 202203021);
	kim.printInfo();
	kim.lunch();
	cout << endl;

	Baek baek("���߰�", "�ڵ��� �б�", 22, 202105156);
	baek.printInfo();
	baek.lunch();
	cout << endl;
}