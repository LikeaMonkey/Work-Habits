#pragma once
#include<vector>
#include "Employee.h"
#include "Worker.h"
#include "Expert.h"
class Manager : public Employee
{
private:
	std::vector<Worker> workers;
	std::vector<Expert> experts;
	std::vector<Manager> managers;
	std::vector<std::string> tasks;
	int doneTasks;
	int min;
public:
	Manager();
	Manager(char*);

	void addWorker(Worker const&);
	void addExpert(Expert const&);
	void addManager(Manager const&);

	void removeWorker();
	void removeExpert();
	void removeManager();

	void printStatus();

	int getNumberTasks()const { return tasks.size(); }

	bool execute(std::string);

	double successRate();
	int numberOfEmployees()const;

	friend std::ostream& operator<<(std::ostream&, Manager const&);

	void addOneTask(std::string);
	void addTasks();
	void doTasks();
};

