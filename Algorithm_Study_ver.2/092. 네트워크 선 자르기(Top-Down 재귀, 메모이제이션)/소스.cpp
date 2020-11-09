// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n;
	int memo[46];
public:
	void facade()
	{
		init();
		std::cout << sol(_n);
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
	int sol(cir n)
	{
		if (memo[n] != 0) return memo[n];
		if (n == 1) return memo[1] = 1;
		if (n == 2) return memo[2] = 2;

		return memo[n] = sol(n - 1) + sol(n - 2);
	}
};

int main()
{
	Problem().facade();

	return 0;
}