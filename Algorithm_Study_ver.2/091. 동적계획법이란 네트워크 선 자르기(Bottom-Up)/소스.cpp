// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
#include <iostream>

class Problem
{
private:
	int _n;
	int memo[46];

public:
	void sol()
	{
		std::cin >> _n;

		memo[1] = 1; memo[2] = 2;
		for (int i = 3; i <= _n; i++)
			memo[i] = memo[i - 1] + memo[i - 2];

		std::cout << memo[_n];
	}
};

int main()
{
	Problem().sol();

	return 0;
}