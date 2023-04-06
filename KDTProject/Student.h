#pragma once

#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <iostream>
#include "Person.h"
using std::cout;
using std::endl;

class Student : public Person{
public:
	Student(string name);
};

#endif __STUDENT_H__
