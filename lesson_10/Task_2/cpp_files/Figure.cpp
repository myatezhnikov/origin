#include "../h_files/Figure.h"
   Figure::Figure() {};

   void Figure::print_info()
    {
        std::cout << this->get_name() << ": " << std::endl;
        std::cout << (this->check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << this->get_sides_count() << std::endl;
        std::cout << std::endl;
    };

    std::string Figure::get_name() { return name; };
    int Figure::get_sides_count() { return sides_count; };
   // int sides_count = 0;
   // std::string name = "Фигура";
    bool Figure::check()
    {
        return !static_cast<bool>(this->get_sides_count());
    };