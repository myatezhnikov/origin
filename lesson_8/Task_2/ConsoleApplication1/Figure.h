#pragma once
#include<iostream>
class Figure
{
    public:
        Figure();
        virtual void print_info();
        virtual void print_creation();
    protected:
        std::string get_name();
        int get_sides_count();
        int sides_count = 0;
        std::string name = "������";
        virtual bool check();
};

