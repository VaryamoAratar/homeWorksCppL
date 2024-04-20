#include <iostream>
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

TEST_CASE("PopFront and PopBack")
{
    SECTION("Получаем значения с пустого списка")
    {
        List test_1;

        try
        {
           std::cout << "Удачное извлечение спереди списка, значение: " << test_1.PopFront() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Невозможно извлечь значение спереди списка. Размер списка: " << test_1.Size() << std::endl;
        }
        try
        {
            std::cout << "Удачное извлечение сзади списка, значение: " << test_1.PopBack() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Невозможно извлечь значение сзади списка. Размер списка: " << test_1.Size() << std::endl;
        }

    }
    SECTION("Получаем значения со списка из 5 значений")
    {
        List test_2;
        for (size_t i = 0; i < 5; i++)
        {
            test_2.PushBack(i + 1);
        }
        try
        {
            std::cout << "Удачное извлечение спереди списка, значение: " << test_2.PopFront() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Невозможно извлечь значение спереди списка. Размер списка: " << test_2.Size() << std::endl;
        }
        try
        {
            std::cout << "Удачное извлечение сзади списка, значение: " << test_2.PopBack() << std::endl;
        }
        catch (...)
        {
            std::cerr << "Невозможно извлечь значение сзади списка. Размер списка: " << test_2.Size() << std::endl;
        }

    }
}
TEST_CASE("PushFront")
{
    SECTION("Добавление спереди")
    {
        List test_2;
        for (size_t i = 0; i < 5; i++)
        {
            test_2.PushFront(i + 1);
        }
        try
        {
            for (size_t i = 5; i > 0; i--)
            {
                REQUIRE(test_2.PopFront() == i);
            }
        }
        catch (...)
        {
            std::cerr << "Ошибка извлечения значение спереди списка"<< std::endl;
        }

    }
}
TEST_CASE("PushBack")
{
    SECTION("Добавление сзади")
    {
        List test_3;
        for (size_t i = 0; i < 5; i++)
        {
            test_3.PushBack(i + 1);
        }
        try
        {
            for (size_t i = 5; i > 0; i--)
            {
                REQUIRE(test_3.PopBack() == i);
            }
        }
        catch (...)
        {
            std::cerr << "Ошибка извлечения значение сзади списка" << std::endl;
        }

    }
}
TEST_CASE_METHOD(List, "Scenario")
{
    List test_4;
    for (size_t i = 0; i < 5; i++)
    {
        test_4.PushBack(i + 1);
        test_4.PushFront((i + 1) * (-1));
    }
    try
    {
        REQUIRE(test_4.PopBack() == 5);
        REQUIRE(test_4.PopFront() == -5);
        test_4.PushFront(-6);
        REQUIRE(test_4.PopFront() == -6);
        REQUIRE(test_4.PopBack() == 4);
        REQUIRE(test_4.PopBack() == 3);
        test_4.PushBack(6);
        REQUIRE(test_4.PopBack() == 6);
    }
    catch (...)
    {
        std::cerr << "Ошибка извлечения значения" << std::endl;
    }

}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "rus");

    return Catch::Session().run(argc, argv);
}