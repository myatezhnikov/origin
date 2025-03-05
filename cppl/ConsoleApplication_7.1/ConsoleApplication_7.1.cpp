#include <iostream>
#include <set>
#include <map>

int main()
{
    std::string str("Hello world!!");
    std::cout << "[IN]: " << str << std::endl;
    std::multiset<char> my_set;
    for (int i = 0; i < str.length(); ++i)      //заносим все символы в multiset
    {
        my_set.insert(str[i]);
    }
    std::map<char, size_t, std::greater<size_t>> my_map; //создаем множество с уникальным ключом и сортируем
    for (const auto& elem : my_set)
    {
        my_map[elem] = my_set.count(elem);              //сохраняем символ и кол-во повторений в строке
    }
    std::multimap<size_t, char> my_multimap;            //переносим данные в множество с неуникальынми элементами
    for (const auto& elem : my_map)
    {
        my_multimap.insert({ elem.second, elem.first });
    }  
    for (auto it = my_multimap.rbegin(); it != my_multimap.rend(); it++)    //выводим в обратном порядке
    {
        std::cout << it->second << " :" << it->first << std::endl;
    }
    system("Pause");
}

