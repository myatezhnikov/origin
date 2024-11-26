#include "Counter.h"
#include<iostream>

    Counter::Counter(int i) { this->i = i; }
    Counter::Counter() { i = 1; }
    void Counter::count_Up()
    {
        this->i = ++this->i;
    }
    void Counter::count_Down()
    {
        this->i = --this->i;
    }
    void Counter::print()
    {
        std::cout << this->i << std::endl;
    }