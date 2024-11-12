#include <iostream>
enum months {
    январь,
    февраль,
    март,
    апрель,
    май,
    июнь,
    июль,
    август,
    сентябрь,
    октябрь,
    ноябрь,
    декабрь
};
using namespace std;
int main(int argc, char** argv)
{
    months m;
    int n;
    setlocale(LC_ALL, "Russian");    
    do {
        cout << "Введите номер месяца: ";
        cin >> n;
        m = static_cast<months>(n);        
            switch (m) {
            case 0: cout << "До свидания" << endl; break;
            case 1: cout << "январь" << endl; break;
            case 2: cout << "февраль" << endl; break;
            case 3: cout << "март" << endl; break;
            case 4: cout << "апрель" << endl; break;
            case 5: cout << "май" << endl; break;
            case 6: cout << "июнь" << endl; break;
            case 7: cout << "июль" << endl; break;
            case 8: cout << "август" << endl; break;
            case 9: cout << "сентябрь" << endl; break;
            case 10: cout << "октябрь" << endl; break;
            case 11: cout << "ноябрь" << endl; break;
            case 12: cout << "декабрь" << endl; break;
            default: cout << "Неправильный номер!" << endl; break;
            }                 
   } while (m != 0);

}