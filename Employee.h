#pragma once
#include<string>

class Employee
{
private:
	char* name;

	void copy(Employee const&);
	void deleteEmployee();
public:
	Employee();
	Employee(char*);
	Employee(Employee const&);
	Employee& operator=(Employee const&);
	~Employee();

	virtual bool execute(std::string) = 0;
	virtual double successRate() = 0;

	void setName(char*);
	char* getName()const { return name; }

	friend std::ostream& operator<<(std::ostream&, Employee const&);
};