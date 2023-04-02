#pragma once

#ifndef __SNACK_H__
#define __SNACK_H__
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Snack {
public:
	static int count;
	static vector<string> hasSnack;

	static void printSnack();
};

#endif