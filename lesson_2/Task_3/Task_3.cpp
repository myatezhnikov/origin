#include <iostream>
#include <string>
struct address {
    std::string city;
    std::string street;
    std::string house; // string - Номер дома может быть цифрой с буквой
    int apart;
    int index;
};
void print(address $a) 
{
    std::cout << "Город: " << $a.city << "\n" << "Улица: " << $a.street << "\n" << "Номер дома: " << $a.house << std::endl;
    std::cout << "Номер квартиры: " << $a.apart << "\n" << "Индекс: " << $a.index << std::endl;
 }
int main()
{
    setlocale(LC_ALL, "Russian");
    address a1, a2;
    a1 = {"Москва","Арбат","12",8,123456};
    a2.city = "Ижевск"; a2.street = "Пушкина"; a2.house = "59"; a2.apart = 143; a2.index = 953769;

    print(a1);
    std::cout << std::endl;
    print(a2);
}