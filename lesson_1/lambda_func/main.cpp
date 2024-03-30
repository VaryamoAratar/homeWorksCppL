#include<iostream>
#include<vector>
#include<algorithm>



int main()
{
	std::vector<int> v{ 4, 7, 9, 14, 12 };
	for (auto i : v)
		std::cout << i << ' ';

	std::for_each(v.begin(), v.end(),
		[](int& n) { if (n % 2)	n *= 3; });

	for (auto i : v)
		std::cout << i << ' ';

	return 0;
}