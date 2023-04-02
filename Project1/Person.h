#pragma once

#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>
using std::string;

class Person {
	static int cnt;
	string name;
public:
	Person(string name);
	static int getCnt();
	static void plusCnt();
};

#endif __PERSON_H__