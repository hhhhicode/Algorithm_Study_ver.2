// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr
#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> nL = nullptr;

public:
	void facade()
	{
		init();
		bubbleSort();
		printRes();
	}
	void init()
	{
		std::cin >> _n;
		nL = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
		{
			std::cin >> nL[i];
		}
	}
	void bubbleSort()
	{
		// index와 index + 1을 비교하여 큰 수를 뒤로 민다.
		auto swap = [this](int& nL1, int& nL2) -> void
		{
			int tmp(nL1);
			nL1 = std::move(nL2);
			nL2 = tmp;
		};

		for (int i = 0; i < _n; i++)
		{
			for (int j = 1; j < _n - i; j++)
			{
				if (nL[j - 1] > nL[j]) swap(nL[j - 1], nL[j]);
			}
		}
	}
	void printRes()
	{
		for (int i = 0; i < _n; i++)
		{
			std::cout << nL[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}