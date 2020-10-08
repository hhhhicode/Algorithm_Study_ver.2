// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>

class Problem
{
	using cir = const int&;
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _r;
	std::unique_ptr<myUnique[]> memo = nullptr;

public:
	void facade()
	{
		init();
		sol(_n, _r);
		std::cout << memo[_n][_r];
	}
	void init()
	{
		auto makeMemo = [this]() -> void
		{
			memo = std::make_unique<myUnique[]>(_n + 1);
			for (int i = 1; i <= _n; i++)
				memo[i] = std::make_unique<int[]>(_r + 1);
		};

		try
		{
			std::cin >> _n >> _r;
			makeMemo();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int sol(cir n, cir r)
	{
		if (n < r || r < 0) return 0; // 실상 필요 없는 부분
		if (n == r || r == 0) return 1; // n == r이거나 r == 0이면 1가지 경우의 수이다. nCn == nC0, nC(n - i) == nCi
		if (memo[n][r] != 0) return memo[n][r];
		return memo[n][r] = sol(n - 1, r - 1) + sol(n - 1, r);
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}