// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr
#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> numList = nullptr;

public:
	void facade()
	{
		init();
		selectionSort();
	}
	void init()
	{
		std::cin >> _n;
		numList = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> numList[i];
	}
	void selectionSort()
	{
		auto swap = [this](int& arr1, int& arr2) -> void
		{
			int tmp = arr1;
			arr1 = std::move(arr2);
			arr2 = tmp;
		};

		int maxValue = 0;
		int count = 0;
		for (int i = 0; i < _n; i++)
		{
			int maxIdx = i;
			for (int j = i + 1; j < _n; j++)
			{
				if (numList[maxIdx] < numList[j]) maxIdx = j;
			}
			if (maxValue != numList[maxIdx])
			{
				count++;
				maxValue = numList[maxIdx];
				if (count == 3)
				{
					std::cout << maxValue;
					return;
				}
			}
			swap(numList[i], numList[maxIdx]);
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}