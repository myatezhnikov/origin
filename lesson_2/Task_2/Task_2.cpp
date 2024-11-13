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
	std::cout << "¬ведите номер счЄта : " << std::endl;
	std::cin >> b.bill; 
	std::cout << "¬ведите им€ владельца : " << std::endl;
	std::cin >> b.name;
	std::cout << "¬ведите баланс : " << std::endl;
	std::cin >> b.balance;
	std::cout << "¬ведите новый баланс : " << std::endl;
	std::cin >> x;
		new_balance (b,x);
	std::cout << "¬аш счЄт : " << b.bill << " " << b.name << " " << b.balance << std::endl;
}