#include "stdafx.h"
#include "Manager.h"
#include<iostream>
#include<fstream>
using namespace std;

Manager::Manager() : Employee() {
	min = 1;
	doneTasks = 0;
}
Manager::Manager(char* newName) : Employee(newName) {
	min = 1;
	doneTasks = 0;
}

void Manager::addWorker(Worker const& newWorker) {
	workers.push_back(newWorker);
}

void Manager::addExpert(Expert const& newExpert) {
	experts.push_back(newExpert);
}

void Manager::addManager(Manager const& newManager) {
	managers.push_back(newManager);
}

void Manager::removeWorker() {
	if (!workers.empty())
		workers.pop_back();
}

void Manager::removeExpert() {
	if (!experts.empty())
		experts.pop_back();
}
void Manager::removeManager() {
	if (!managers.empty())
		managers.pop_back();
}

void Manager::printStatus() {
	int num = 1;
	for (int i = 0; i < workers.size(); i++) {
		cout << num++ << "  " << workers[i].getName() << ": success rate "
			<< workers[i].successRate() << endl;
	}
	for (int i = 0; i < experts.size(); i++) {
		cout << num++ << "  " << experts[i].getName() << ": success rate "
			<< experts[i].successRate() << endl;
	}
	for (int i = 0; i < managers.size(); i++) {
		cout << num++ << "  " << managers[i].getName() << ": success rate "
			<< managers[i].successRate() << endl;
	}
}

bool Manager::execute(string task) {
	for (int i = 0; i < workers.size(); i++) {
		if (workers[i].getNumberTasks() < min) {
			cout << " " << workers[i].getName();
			if (workers[i].execute(task)) {
				doneTasks++;
				return true;
			}
			return false;
		}
	}
	for (int i = 0; i < experts.size(); i++) {
		if (experts[i].getNumberTasks() < min) {
			cout << " " << experts[i].getName();
			if (experts[i].execute(task)) {
				doneTasks++;
				return true;
			}
			return false;
		}
	}
	for (int i = 0; i < managers.size(); i++) {
		if (managers[i].tasks.size() < min) {
			cout << " " << managers[i].getName();
			managers[i].addOneTask(task);
			if (managers[i].execute(task)) {
				doneTasks++;
				return true;
			}
			return false;
		}
	}
	min++;
	cout << " " << workers[0].getName();
	if (workers[0].execute(task)) {
		doneTasks++;
		return true;
	}
	return false;
}

double Manager::successRate() {
	if (tasks.size() == 0) return 0;
	return (double)doneTasks / tasks.size();
}
int Manager::numberOfEmployees()const {
	return workers.size() + experts.size() + managers.size();
}

ostream& operator<<(ostream& os, Manager const& manager) {
	os << "manager : " << manager.numberOfEmployees() << " " << manager.getName() << endl;
	return os;
}

void Manager::addOneTask(string task) {
	tasks.push_back(task);
}

void Manager::addTasks() {
	ifstream newTasks("task.txt");
	if (newTasks.is_open()) {
		int i = 0;
		while (!newTasks.eof()) {
			string task;
			getline(newTasks, task);
			tasks.push_back(task);
		}
	}
	newTasks.close();
}

void Manager::doTasks() {
	for (int i = 0; i < tasks.size(); i++) {
		cout << i + 1 << "  " << tasks[i] << " -- ";
		if (execute(tasks[i])) cout << " (SUCCESS)\n";
		else cout << " (FAIL)\n";
	}
}