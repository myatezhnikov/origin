#include <iostream>
#include<fstream>
#include<string>
class address
{
private:
    std::string city;
    std::string street;
    std::string house; // string - Номер дома может быть цифрой с буквой
    int apart;
public:
    address(std::string city, std::string street, std::string house, int apart)
    {
        this->city = city; this->street = street; this->house = house; this->apart = apart;
    }
    address()
    {
        this->city = "city"; this->street = "street"; this->house = "house"; this->apart = 1;
    }
    std::string get_output_address()
    {
        return this->city + ", " + this->street + ", " + this->house + ", " + std::to_string(this->apart);
    }
    void set_address(std::string city, std::string street, std::string house, int apart)
    { 
        if (city != "") this->city = city;
        if (street != "") this->street = street;
        if (house != "") this->house = house;
        if (apart != 0) this->apart = apart;       
    }
    
};

int main()
{
    setlocale(LC_ALL, "Russian");  
    int size;  
    
    std::ifstream file("in.txt");
    if (file.is_open())
    {
        file >> size;
        address* arr = new address[size];
        std::string s1, s2, s3;
        int x;
        for (int i = 0; i < size; i++)
        {           
           file >> s1;
           file >> s2;
           file >> s3;
           file >> x;
           arr[i].set_address(s1, s2, s3, x);
        }
         file.close();
         std::ofstream out("out.txt");
         if (out.is_open())
         {
            out << size;
            for (int i = size-1; i >=0; i--)
            {
                out << std::endl << arr[i].get_output_address(); 
            }
         }
        out.close();
       delete[] arr;
    }
}
