#include <Catch2/


TEST_CASE("PopFront and PopBack")
{
    SECTION("�������� �������� � ������� ������")
    {
        List test_1;

        try
        {
            std::cout << "������� ���������� ������� ������, ��������: " << test_1.PopFront() << std::endl;
        }
        catch (...)
        {
            std::cerr << "���������� ������� �������� ������� ������. ������ ������: " << test_1.Size() << std::endl;
        }
        try
        {
            std::cout << "������� ���������� ����� ������, ��������: " << test_1.PopBack() << std::endl;
        }
        catch (...)
        {
            std::cerr << "���������� ������� �������� ����� ������. ������ ������: " << test_1.Size() << std::endl;
        }

    }
    SECTION("�������� �������� �� ������ �� 5 ��������")
    {
        List test_2;
        for (size_t i = 0; i < 5; i++)
        {
            test_2.PushBack(i + 1);
        }
        try
        {
            std::cout << "������� ���������� ������� ������, ��������: " << test_2.PopFront() << std::endl;
        }
        catch (...)
        {
            std::cerr << "���������� ������� �������� ������� ������. ������ ������: " << test_2.Size() << std::endl;
        }
        try
        {
            std::cout << "������� ���������� ����� ������, ��������: " << test_2.PopBack() << std::endl;
        }
        catch (...)
        {
            std::cerr << "���������� ������� �������� ����� ������. ������ ������: " << test_2.Size() << std::endl;
        }

    }
}
TEST_CASE("PushFront")
{
    SECTION("���������� �������")
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
            std::cerr << "������ ���������� �������� ������� ������" << std::endl;
        }

    }
}
TEST_CASE("PushBack")
{
    SECTION("���������� �����")
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
            std::cerr << "������ ���������� �������� ����� ������" << std::endl;
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
        std::cerr << "������ ���������� ��������" << std::endl;
    }

}
