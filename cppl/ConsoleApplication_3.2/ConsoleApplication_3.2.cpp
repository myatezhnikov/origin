#include <iostream>
class smart_array
{
public:
	int* arr = nullptr;
	int logical_size{ 0 };		//логический размер массива, счетчик
	int actual_size{ 0 };	//реальный размер массива
	smart_array(size_t actual_size)		//конструктор с размером массива
	{
		this->actual_size = actual_size;
		arr = new int[actual_size];
	}
	void add_element(size_t index_element)		//добавляем элемент проверяя не выход за диапазон
	{
		if (this->actual_size > logical_size) //если логический размер массива позволяет добавить новый элеменет
		{
			arr[logical_size] = index_element;	//добавляем элемент в массив
			logical_size++;					//увеличивем логический размер после добавления элемента
		} else 
			{ 
				std::cout << "Выход за пределы массива" << std::endl; 
			}
	}
	int get_element(size_t index_element)		//считываем элемент проверяя не выход за диапазон
	{
		if (this->actual_size > index_element)
		{
			return arr[index_element];
		} else 
			{ 
				throw std::out_of_range("Выход за пределы массива"); 
			}
	}

	~smart_array()	//деструктор
	{
		delete[] arr;
	}
	smart_array& operator=(smart_array& new_array)	//перегрузка оператора "="
	{
		delete[] arr;		//удаляем массив слева от "="
		this->actual_size = new_array.actual_size; //новые значения реального размера и логического размера массива
		this->logical_size = new_array.logical_size;
		arr = new int[this->actual_size]; //создаем новый массив 
		
		for (int i = 0; i < this->actual_size; i++)
		{
			arr[i] = new_array.get_element(i);      //копируем в него массив справа от "="
		}		
		return *this;			//возвращаем скопированный массив
	}
	void print()			//функция вывода на экран массива
	{
		std::cout << "Адрес массива = " << &arr << std::endl;	
		for (int i = 0; i < logical_size; i++)  // вывод на экран массива логического, а не фактического размера
		{
			std::cout << "Элемент " << i << " = " << get_element(i) << std::endl;
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