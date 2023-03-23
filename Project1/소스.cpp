#include <iostream>

//using namespace std;

int main() {
	std::string str = "Hello World";
	std::string str2 = "!!!";
	
	str = str + str2;
	std::cout << str;

	return 0;
}