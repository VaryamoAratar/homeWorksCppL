﻿#include <iostream>
#include <catch.hpp>

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

TEST_CASE("Тест методов Empty, Clear, Size двусвязного списка")
{
    List test;
    SECTION("Пустой список")
    {
        REQUIRE(test.Empty() == 1);
        REQUIRE(test.Size() == 0);
        test.Clear();
    }
    SECTION("Один элемент в списке")
    {
        test.PushBack(10);
        REQUIRE(test.Empty() == 0);
        SECTION("Error")
        {
            INFO("Проверка Empty");
            REQUIRE(test.Empty() == 1);
        }
        REQUIRE(test.Size() == 1);
        test.Clear();
        REQUIRE(test.Empty() == 1);
        REQUIRE(test.Size() == 0);
    }
    SECTION("Пять элементов в списке")
    {
        test.PushBack(10);
        test.PushBack(20);
        test.PushBack(30);
        test.PushBack(40);
        test.PushBack(50);

        REQUIRE(test.Empty() == 0);
        REQUIRE(test.Size() == 5);
        test.Clear();
        REQUIRE(test.Empty() == 1);
        REQUIRE(test.Size() == 0);

    }
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");

   return Catch::Session().run(argc, argv);
}