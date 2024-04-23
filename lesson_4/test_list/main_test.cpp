#include <catch.hpp>
#include <cstdint>
#include <List.h>

TEST_CASE("Check Empty", "[List]")
{
	List test_1;
	REQUIRE(test_1.Empty() == true);
	test_1.PushBack(1);
	REQUIRE(test_1.Empty() == false);
}
TEST_CASE("CHeck Size", "[List]")
{
	List test_2;
	REQUIRE(test_2.Size() == 0);
	test_2.PushBack(1);
	REQUIRE(test_2.Size() == 1);
}
TEST_CASE("Chech Clear", "[List]")
{
	List test_3;
	for (size_t i = 0; i < 3; i++) test_3.PushBack(i);
	REQUIRE(test_3.Size() == 3);
	test_3.Clear();
	REQUIRE(test_3.Size() == 0);
}
