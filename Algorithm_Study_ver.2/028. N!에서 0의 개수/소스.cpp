// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr
#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> primes;

public:
	void facade()
	{
		init();
		run();
	}
	void init()
	{
		std::cin >> _n;
		primes = std::make_unique<int[]>(_n + 1);
	}
	void run()
	{
		auto searchZero = [this]() -> int
		{
			int count(primes[2] > primes[5] ? primes[5] : primes[2]);
			return count;
		};

		for (int i = 1; i <= _n; i++)
		{
			int tmp = i;
			int num = 2;
			while (tmp != 1)
			{
				if (tmp % num == 0)
				{
					primes[num]++;
					tmp /= num;
				}
				else
				{
					num++;
				}
			}
		}
		std::cout << searchZero();
	}

	void test()
	{
		std::cout << _n << ' ' << std::endl;
		for (int i = 1; i < _n + 1; i++)
		{
			std::cout << primes[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}