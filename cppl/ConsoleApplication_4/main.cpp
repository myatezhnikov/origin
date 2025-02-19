#include <iostream>
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};
TEST_CASE("Empty", "[Empty]")
{
    List list;
    REQUIRE_FALSE(!list.Empty()); //Проверка на пустоту   
}
TEST_CASE("Size", "[Size]")
{
    List list;
    list.PushFront(1);
    list.PushFront(2);
    REQUIRE(list.Size() == 2); // проверка на размер
}
TEST_CASE("Clear", "[Clear]")
{
    List list;
    list.PushFront(1);
    list.Clear();
    REQUIRE(list.Size() == 0);  //проверка на очистку
}
TEST_CASE("Multitest", "[pop,front,back]")
{
    List list;
    list.PushFront(4);          // добавляем элемент в начало
    list.PushFront(3);           // добавляем элемент в начало
    list.PushBack(20);           // добавляем элемент в конец

    // список 3, 4 , 20
    REQUIRE(list.Size() == 3); //проверяем размер, 3 элемента
    REQUIRE(list.PopFront() == 3); //удаляем первый эдемент 3   
    REQUIRE(list.PopBack() == 20); //удаляем последний элемент 20               
    REQUIRE(list.Size() == 1);     // проверяем размер, 1 элемент

    list.Clear();           //очищаем список

    REQUIRE_THROWS(list.PopFront());    // проверяем на выброс исключений
    REQUIRE_THROWS(list.PopBack());      // проверяем на выброс исключений

}
