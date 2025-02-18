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
		if (this->size > i) { arr[i] = elem; i++; }
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
	smart_array& operator=(smart_array& new_array)	//перегрузка оператора "="
	{
		delete[] arr;		//удаляем массив слева от "="
		this->size = new_array.size; //новые значения размера и индекса (логического размера массива)
		this->i = new_array.i;
		arr = new int[this->size]; //создаем новый массив 
		
		for (int k = 0; k < this->size; k++)
		{
			arr[k] = new_array.get_element(k);      //копируем в него массив справа от "="
		}		
		return *this;			//возвращаем скопированный массив
	}
	void print()			//функция вывода на экран массива
	{
		std::cout << "Адрес массива = " << &arr << std::endl;	
		for (int k = 0; k < i; k++)  // вывод на экран массива логического, а не фактического размера
		{
			std::cout << "Элемент " << k << " = " << get_element(k) << std::endl;
		}
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

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr.print();			//выведем на экран массивы и их адреса
		new_array.print();

		arr = new_array;		// присвоим один массив другому

		arr.print();			//выведем новый массив на экран

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	system("Pause");
};