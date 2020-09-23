// 틀린 문제.
// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr, try
// auto, lambda, using, unique_ptr, try
#include <iostream>
#include <limits>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _c;	// n : 마구간 개수, c : 말 개수
	myUnique xi;	// 마구간 좌표

public:
	void facade()
	{
		init();
		std::cout << binarySearch();
	}

	void init()
	{
		try
		{
			std::cin >> _n >> _c;
			xi = std::make_unique<int[]>(_n);
			for (int i = 0; i < _n; i++)
				std::cin >> xi[i];
			selectionSort(xi);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void selectionSort(myUnique& xi)
	{
		for (int i = 1; i < _n; i++)
		{
			auto tmp(xi[i]);
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (tmp < xi[j])
				{
					xi[j + 1] = xi[j];
				}
				else break;
			}
			xi[j + 1] = tmp;
		}
	}

	int binarySearch()
	{
		auto horseCheck = [this](const int& mid, int& min) -> int
		{	// 맨 앞 마구간에 말이 1마리 이미 들어가 있다.
			int thisPosition(xi[0]);
			int count(1);

			for (int i = 1; i < _n; i++)
			{
				int len = xi[i] - thisPosition;
				if (mid < len)
				{
					count++;
					thisPosition = xi[i];
					// mid 기준일 때, 가장 가까운 말의 거리 구하기.
					if (min > len)
						min = len;
				}
			}
			return count;
		};

		int lt(xi[0]), rt(xi[_n - 1]);
		int max(0);

		while (lt <= rt)
		{
			int mid((lt + rt) / 2);

			int min(std::numeric_limits<int>::max());
			
			if (horseCheck(mid, min) >= _c)
			{
				if (max < min)
					max = min;
				lt = mid + 1;
			}
			else
			{
				rt = mid - 1;
			}
		}

		return max;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}