#pragma once
#include "Employee.h"

class Expert : public Employee
{
private:
	int numberTasks;
public:
	Expert();
	Expert(char*);

	int getNumberTasks()const { return numberTasks; }

	bool execute(std::string);
	double successRate();

	friend std::ostream& operator<<(std::ostream&, Expert const&);
};

