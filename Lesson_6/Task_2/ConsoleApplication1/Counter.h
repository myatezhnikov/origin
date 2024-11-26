#pragma once
class Counter
{
private:
    int i = 1;
public:
    Counter(int i);
    Counter();
    void count_Up();
    void count_Down();
    void print();
};

