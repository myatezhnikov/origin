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
		}
		else { std::cout << "Выход за пределы массива" << std::endl; }
	}
	int get_element(size_t index_element)		//считываем элемент проверяя не выход за диапазон
	{ 
		if (this->actual_size > index_element) 
		{ 
			return arr[index_element]; 
		}
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