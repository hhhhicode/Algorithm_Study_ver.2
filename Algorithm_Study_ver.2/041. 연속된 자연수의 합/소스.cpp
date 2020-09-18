// 아이디어 틀림.

// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr

#include <iostream>

class Problem
{
private:
	int _n;
	int count = 0;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		std::cin >> _n;
	}

	void solution()
	{
		int number = _n;
		int count = 0;
		int b = 1;

		number--;
		while (number > 0)
		{
			b++;
			number = number - b;
			if (number % b == 0)
			{
				for (int i = 1; i < b; i++)
				{
					std::cout << number / b + i << " + ";
				}
				std::cout << number / b + b  << " = " << _n << std::endl;
				count++;
			}
		}
		std::cout << count;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}