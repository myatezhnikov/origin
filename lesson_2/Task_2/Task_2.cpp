#include <iostream>
#include <string>
struct bank_account {
	int bill = 0;
	std::string name = " ";
	double balance = 0;
};
void new_balance(bank_account &b, double &x)
{	b.balance = x; }
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");
	bank_account b;
	double x;
	std::cout << "������� ����� ����� : " << std::endl;
	std::cin >> b.bill; 
	std::cout << "������� ��� ��������� : " << std::endl;
	std::cin >> b.name;
	std::cout << "������� ������ : " << std::endl;
	std::cin >> b.balance;
	std::cout << "������� ����� ������ : " << std::endl;
	std::cin >> x;
		new_balance (b,x);
	std::cout << "��� ���� : " << b.bill << " " << b.name << " " << b.balance << std::endl;
}