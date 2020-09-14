// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto
#include <iostream>

class Problem
{
private:
	int _n;

public:
	void facade()
	{
		init();
		run();
	}
	void init()
	{
		std::cin >> _n;
	}
	void run()
	{
		auto count(0);
		for (int i = 1; i <= _n; i++)
		{
			auto tmp(i);
			while (tmp != 0)
			{
				if (tmp % 10 == 3)
				{
					count++;
				}
				tmp /= 10;
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