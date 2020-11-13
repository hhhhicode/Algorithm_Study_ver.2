// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

// 1 : 1~9 : 9°³
// 2 : 10~99 : 90°³
// 3 : 100~999 : 900°³ ...

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n;
public:
	void facade()
	{
		init();
		std::cout << sol();
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
	int sol()
	{
		int max = 9, t = 1, e = 1;
		int sum = 0;
		while (max <= _n)
		{
			sum += 9 * t * e;
			
			t *= 10, e++;
			max += 9 * t;
		}
		sum += (_n - max/10) * e;

		return sum;
	}
};

int main()
{
	Problem().facade();

	return 0;
}