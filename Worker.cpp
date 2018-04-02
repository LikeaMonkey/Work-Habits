#include "stdafx.h"
#include "Worker.h"
#include<iostream>
using namespace std;

Worker::Worker() : Employee() {
	k = 10;
	numberTasks = 0;
	doneTasks = 0;
}

Worker::Worker(char* newName, int newK) : Employee(newName) {
	if (newK > 0) k = newK;
	else k = 10;
	numberTasks = 0;
	doneTasks = 0;
}

void Worker::setK(int newK) {
	if (newK > 0) k = newK;
	else k = 10;
}

bool Worker::execute(string task) {
	if (++numberTasks % k == 0) {
		return false;
	}
	doneTasks++;
	return true;
}
double Worker::successRate() {
	if (numberTasks == 0) return 0;
	return (double)doneTasks / numberTasks;
}

ostream& operator<<(ostream& os, Worker const& worker) {
	os << "worker : " << worker.getK() << " " << worker.getName() << endl;
	return os;
}