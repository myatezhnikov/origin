#include<iostream>
#include <windows.h>
#include "Dynamic_.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	string s;
	cout << "������� ���: ";
	cin >> s;
	Leaver l;
	cout << l.leave(s) << endl;

	system("Pause");
	return 0;
}