// 선택정렬 알고리즘에 대해 기록후 자주 보기

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
		selectionSort();
		printList();
	}
	void init()
	{
		std::cin >> _n;
		list = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}
	void selectionSort()
	{
		auto swap = [this](int& list1, int& list2) -> void
		{
			int tmp = list1;
			list1 = std::move(list2);
			list2 = tmp;
		};

		for (int i = 0; i < _n; i++)
		{
			int minIdx = i;
			for (int j = i + 1; j < _n; j++)
			{
				if (list[minIdx] > list[j]) minIdx = j;
			}
			swap(list[i], list[minIdx]);
		}
	}

	void printList()
	{
		for (int i = 0; i < _n; i++)
		{
			std::cout << list[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}