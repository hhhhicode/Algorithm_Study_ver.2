// 중요한 정렬

// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr

#include <iostream>

class Problem
{
	using uniqueIntArr = std::unique_ptr<int[]>;

private:
	int _n;
	uniqueIntArr list = nullptr;

public:
	void facade()
	{
		init();
		insertSort();
		printList();
	}
	void init()
	{
		std::cin >> _n;
		list = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}
	void insertSort()
	{
		for (int i = 1; i < _n; i++)
		{
			auto tmp(list[i]);
			int j = i - 1;
			for (; 0 <= j; j--)
			{
				if (tmp < list[j])
				{
					list[j + 1] = list[j];
				}
				else break;
			}
			list[j + 1] = tmp;
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