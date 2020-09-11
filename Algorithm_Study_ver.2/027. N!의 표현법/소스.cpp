// 소인수 분해를 이용한다. 아이디어를 떠올리지 못했다.

// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr
#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> divNum;

public:
	void facade()
	{
		init();
		factorial();
		printDivNum();
	}
	void init()
	{
		std::cin >> _n;
		divNum = std::make_unique<int[]>(_n + 1);
	}
	void factorial()
	{
		auto func = [this](int number) -> void
		{
			int diviser = 2;
			while (number != 1)
			{
				if (number % diviser == 0)
				{
					divNum[diviser]++;
					number /= diviser;
				}
				else
					diviser++;
			}
		};

		for (int i = 2; i <= _n; i++)
		{
			func(i);
		}
	}

	void printDivNum()
	{
		std::cout << _n << "! = ";
		for (int i = 2; i <= _n; i++)
		{
			if (divNum[i] != 0)
				std::cout << divNum[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}