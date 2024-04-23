#include <catch.hpp>
#include <cstdint>
#include <List.h>

TEST_CASE("Check PushBack", "[List]")
{
	List test_1;
	test_1.PushBack(1);
	REQUIRE(test_1.Size() == 1);
}
TEST_CASE("CHeck PushFront", "[List]")
{
	List test_2;
	test_2.PushFront(-1);
	REQUIRE(test_2.Size() == 1);
}
TEST_CASE("Chech PopBack", "[List]")
{
	List test_3;
	test_3.PushBack(1);
	test_3.PushBack(2);
	test_3.PushBack(3);
	REQUIRE(test_3.PopBack() == 3);
}
TEST_CASE("Check PopFront", "[List]")
{
	List test_4;
	test_4.PushBack(1);
	test_4.PushBack(2);
	test_4.PushBack(3);
	REQUIRE(test_4.PopFront() == 1);
}
SCENARIO("Multiple method calls", "[List]")
{
	GIVEN("Creating an empty list and adding three items")
	{
		List list_test;

		REQUIRE(list_test.Empty() == true);
		REQUIRE(list_test.Size() == 0);

		WHEN("Extracting an item from an empty list")
		{
			REQUIRE_THROWS(list_test.PopBack() == true);
			REQUIRE_THROWS(list_test.PopFront() == true);
		}

		list_test.PushBack(-1);
		list_test.PushBack(0);
		list_test.PushBack(1);

		REQUIRE(list_test.Empty() == false);
		REQUIRE(list_test.Size() == 3);

		WHEN("Adding an element to the end")
		{
			list_test.PushBack(2);
			THEN("the size should increase")
			{
				REQUIRE(list_test.Size() == 4);
			}
		}
		WHEN("Adding an element to the front")
		{
			list_test.PushFront(-2);
			THEN("the size should increase")
			{
				REQUIRE(list_test.Size() == 4);
			}
		}
		WHEN("Extracting the element from the end")
		{
			int t = list_test.PopBack();
			THEN("The value of the element is 1 and the size should decrease")
			{
				REQUIRE(t == 1);
				REQUIRE(list_test.Size() == 2);
			}
		}
		WHEN("Extracting the element from the front")
		{
			int t = list_test.PopFront();
			THEN("The value of the element is -1 and the size should decrease")
			{
				REQUIRE(t == -1);
				REQUIRE(list_test.Size() == 2);
			}
		}
	}
}