#pragma once
#include "Employee.h"

class Worker : public Employee
{
private:
	int k;          // Fail every k-th task
	int numberTasks;
	int doneTasks;
public:
	Worker();
	Worker(char*, int);

	void setK(int newK);

	bool execute(std::string);
	double successRate();

	int getNumberTasks()const { return numberTasks; }
	int getDoneTasks()const { return doneTasks; }
	int getK()const { return k; }

	friend std::ostream& operator<<(std::ostream&, Worker const&);
};

