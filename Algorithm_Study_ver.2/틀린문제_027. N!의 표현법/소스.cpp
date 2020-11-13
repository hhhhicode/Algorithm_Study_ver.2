// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

// 5! = 1 * 2 * 3 * 4* 5 이므로 곱해지는 모든 수를 소인수 분해 하여 곱해도 같은 값이 된다.

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n;
	int prime[1001]{ 0, };
public:
	void facade()
	{
		init();
		sol();
		printRes();
	}
	void init()
	{
		try
		{
			std::cin >> _n;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		for (int i = 2; i <= _n; i++)
		{
			int diviser = 2;
			int tmp = i;
			while (tmp != 1)
			{
				if (tmp % diviser == 0)
				{
					tmp /= diviser;
					prime[diviser]++;
				}
				else diviser++;
			}
		}
	}
	void printRes()
	{
		std::cout << _n << "! = ";
		for (int i = 2; i <= 1000; i++)
			if (prime[i] != 0) std::cout << prime[i] << ' ';
	}
};

int main()
{
	Problem().facade();

	return 0;
}