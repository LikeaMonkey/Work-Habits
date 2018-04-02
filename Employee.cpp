#include "stdafx.h"
#include "Employee.h"
#include<iostream>
using namespace std;

Employee::Employee() {
	name = new char[1];
	name = "";
}

Employee::Employee(char* newName) {
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

Employee::Employee(const Employee &newEmployee) {
	copy(newEmployee);
}

Employee& Employee::operator=(const Employee& newEmployee) {
	if (this != &newEmployee) {
		deleteEmployee();
		copy(newEmployee);
	}
	return *this;
}

Employee::~Employee() {
	deleteEmployee();
}

void Employee::copy(Employee const& newEmployee) {
	if (newEmployee.name) {
		name = new char[strlen(newEmployee.name) + 1];
		strcpy_s(name, strlen(newEmployee.name) + 1, newEmployee.name);
	}
	else {
		name = new char[1];
		name = "";
	}
}

void Employee::deleteEmployee() {
	if (name) delete name;
}

void Employee::setName(char* newName) {
	if (name) delete name;
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

ostream& operator<<(ostream& os, Employee const& employee) {
	os << "Employee : " << employee.getName() << endl;
	return os;
}