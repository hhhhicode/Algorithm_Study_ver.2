// 어설픈 아이디어.

// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr

#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> list = nullptr;

public:
	void facade()
	{
		init();
		customBubbleSort();
		printList();
	}
	void init()
	{
		std::cin >> _n;
		list = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}
	void customBubbleSort()
	{
		auto swap = [this](int& list1, int& list2) -> void
		{
			int tmp(list1);
			list1 = std::move(list2);
			list2 = tmp;
		};

		for (int i = 0; i < _n; i++)
		{
			for (int j = 1; j < _n - i; j++)  // <- 이부분이 중점이다.
			{
				if (0 < list[j - 1] && list[j] < 0)
				{
					swap(list[j - 1], list[j]);
				}
			}
		}
	}
	void printList()
	{
		for (int i = 0; i < _n; i++)
			std::cout << list[i] << ' ';
		std::cout << std::endl;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}