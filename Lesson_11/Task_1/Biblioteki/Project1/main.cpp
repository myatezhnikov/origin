#include<iostream>
#include <windows.h>
#include "Static.h"
//#include "Dynamic.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	string s;
	cout << "¬ведите им€: ";
	cin >> s;
	Leaver l;
	cout << l.leave(s) << endl;

	system("Pause");
	return 0;
}