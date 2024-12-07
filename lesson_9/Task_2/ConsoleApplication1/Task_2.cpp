#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;	

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}	
	//Fraction() {};
	bool operator==(Fraction other) { return (this->numerator_ / this->denominator_) == (other.numerator_ / other.denominator_); }
	bool operator!=(Fraction other) { return !(*this == other); }
	bool operator>(Fraction other) { return (this->numerator_ / this->denominator_) > (other.numerator_ / other.denominator_); }
	bool operator<(Fraction other) { return other > *this; }
	bool operator>=(Fraction other) { return !(other > *this); }
	bool operator<=(Fraction other) { return !(*this > other); }
	Fraction operator+(Fraction other)
	{
		int x = (this->numerator_ * other.denominator_) + (other.numerator_ * this->denominator_);
		int y = this->denominator_ * other.denominator_;		
		int z = abs(O_Delitel(x, y));
		return Fraction(x/z, y/z);
	};	
	Fraction operator-(Fraction other)
	{
		int x = (this->numerator_ * other.denominator_) - (other.numerator_ * this->denominator_);
		int y = this->denominator_ * other.denominator_;
		int z = abs(O_Delitel(x, y));
		return Fraction(x / z, y / z);
	};
	Fraction operator*(Fraction other)
	{
		int x = (numerator_ * other.numerator_);
		int y = (denominator_ * other.denominator_);
		int z = abs(O_Delitel(x, y));
		return Fraction(x / z, y / z);
	};
	Fraction operator/(Fraction other)
	{
		int x = (numerator_ * other.denominator_);
		int y = (denominator_ * other.numerator_);
		int z = abs(O_Delitel(x, y));
		return Fraction(x / z, y / z);
	};
	Fraction& operator++() { numerator_ = numerator_ + denominator_; return *this; };
	Fraction operator++(int) { Fraction temp = *this; ++(*this); return *this; };
	Fraction& operator--() { numerator_ = numerator_ - denominator_; return *this; };
	Fraction operator--(int) { Fraction temp = *this; --(*this); return *this; };
		
	Fraction operator-() { return Fraction(((- 1) * numerator_), denominator_); };

	std::string Print() { return std::to_string(this->numerator_) + "/" + std::to_string(this->denominator_); }

private:
	int O_Delitel(int x, int y) // рекурсиваная функция нахождения общего делителя для сокращения
	{		
		if (y == 0) return x;
		return O_Delitel(y, x % y);
	};	
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x{ 0 }, y{ 0 };
	std::cout << "Введите числитель дроби 1: "; std::cin >> x; 
	std::cout << "Введите знаменатель дроби 1 : "; std::cin >> y;
	Fraction f1(x, y);
	std::cout << "Введите числитель дроби 2: "; std::cin >> x; 
	std::cout << "Введите знаменатель дроби 2 : "; std::cin >> y; 
	Fraction f2(x, y);

	//std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << std::endl;
	//std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << std::endl;
	//std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << std::endl;
	//std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << std::endl;
	//std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << std::endl;
	//std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << std::endl;
	
		
	std::cout << f1.Print() << " + " << f2.Print() << " = " << (f1+f2).Print() << std::endl;	
	std::cout << f1.Print() << " - " << f2.Print() << " = " << (f1 - f2).Print() << std::endl;
	std::cout << f1.Print() << " * " << f2.Print() << " = " << (f1 * f2).Print() << std::endl;
	std::cout << f1.Print() << " / " << f2.Print() << " = " << (f1 / f2).Print() << std::endl;
	std::cout << f1.operator-().Print() << " " << f2.operator-().Print() << " Унарный оператор" << std::endl;
	
	std::cout << std::endl;
	std::cout << "++" << f1.Print() << " * " << f2.Print() << " = ";
	std::cout << (f1.operator++() * f2).Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;
	std::cout << std::endl;
	std::cout << f1.Print() << "-- * " << f2.Print() << " = ";
	std::cout << (f1 * f2).Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.operator--(1).Print() << std::endl;
	std::cout << std::endl;
	std::cout << f1.Print() << "++ * " << f2.Print() << " = ";
	std::cout << (f1 * f2).Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.operator++(1).Print() << std::endl;
	std::cout << std::endl;
	std::cout << "--" << f1.Print() << " * " << f2.Print() << " = ";
	std::cout << (f1.operator--() * f2).Print() << std::endl;
	std::cout << "Значение дроби 1 = " << f1.Print() << std::endl;

	return 0;
}


