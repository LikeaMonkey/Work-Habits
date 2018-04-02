#include "stdafx.h"
#include<iostream>
#include"Employee.h"
#include"Worker.h"
#include"Expert.h"
#include"Manager.h"
using namespace std;

int main()
{
	Manager man1("Angel Angelov");
	Worker wor1("Boqn Boqnov", 2);
	Expert exp1("Vasilka Vasileva");
	Worker wor2("Dimitur Dimitrov", 4);
	Manager man2("Georgi Georgiev");

	man2.addWorker(wor2);
	man2.printStatus();

	cout << "--------------------------" << endl;

	man1.addWorker(wor1);
	man1.addExpert(exp1);
	man1.addManager(man2);
	man1.printStatus();

	cout << "--------------------------" << endl;

	cout << man1 << wor1 << exp1 << man2 << wor2;

	cout << "--------------------------" << endl;

	man1.addTasks();
	man1.doTasks();
	cout << endl;
	man1.printStatus();
	cout << "--------------------------" << endl;

	system("pause");
    return 0;
}