#include <iostream>
class smart_array
{
public:
	int* arr = nullptr;
	int i{ 0 };		//логический размер массива, счетчик
	int size{ 0 };	//размер массива
	smart_array(int size)		//конструктор с размером массива
	{
		this->size = size;
		arr = new int[size];
	}
	void add_element(int elem)		//добавляем элемент проверяя не выход за диапазон
	{
		if (this->size > i) { arr[i] = elem; i++;	}
		else { std::cout << "Выход за пределы массива" << std::endl; }
	}
	int get_element(int elem)		//считываем элемент проверяя не выход за диапазон
	{ 
		if ((this->size > elem) && (elem >= 0)) { return arr[elem]; }
		else { throw std::out_of_range("Выход за пределы массива"); }
	}
	
	~smart_array()	//деструктор
	{
		delete[] arr; 
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	system("Pause");
};