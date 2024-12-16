#pragma once
#include<iostream>
#ifdef BIBLIOTEKA_EXPORTS
#define BIBLIOTEKA __declspec(dllexport)
#else
#define BIBLIOTEKA __declspec(dllimport)
#endif

class BIBLIOTEKA Figure
{
    public:
        Figure();
        virtual void print_info();
    protected:
        std::string get_name();
        int get_sides_count();
        int sides_count = 0;
        std::string name = "Фигура";
        virtual bool check();
};

