#include "stdafx.h"
#include "Expert.h"
#include<iostream>
using namespace std;

Expert::Expert() : Employee() {
	numberTasks = 0;
}

Expert::Expert(char* newName) : Employee(newName) {
	numberTasks = 0;
}

bool Expert::execute(string task) {
	numberTasks++;
	return true;
}
double Expert::successRate() {
	if (numberTasks == 0) return 0;
	return 1;
}

ostream& operator<<(ostream& os, Expert const& expert) {
	os << "expert : " << expert.getName() << endl;
	return os;
}