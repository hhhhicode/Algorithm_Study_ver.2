// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, try

#include <iostream>
#include <algorithm>

using cir = const int&;

class Problem
{
private:
	int _n;
	int res;
	int** map = nullptr;
	int** memo = nullptr;

public:
	~Problem()
	{
		for (int i = 0; i < _n + 1; i++)
			delete[] map[i], memo[i];
		delete[] map, memo;
	}
	void facade()
	{
		init();
		res = sol(_n, _n);
		std::cout << res;
	}
	void init()
	{
		auto makeMapAndMemo = [this](const auto& _n) -> void
		{
			map = new int* [_n + 1];
			memo = new int* [_n + 1];
			for (int i = 0; i < _n + 1; i++)
			{
				map[i] = new int[_n + 1]();
				memo[i] = new int[_n + 1]();
			}
			for (int i = 1; i < _n + 1; i++)
				for (int j = 1; j < _n + 1; j++)
					std::cin >> map[i][j];
		};

		try
		{
			std::cin >> _n;
			makeMapAndMemo(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int sol(cir r, cir c)
	{
		if (memo[r][c] != 0) return memo[r][c];
		if (r == 1 && c == 1) return memo[1][1] = map[1][1];
		if (r == 0 || c == 0) return std::numeric_limits<int>::max();

		return memo[r][c] = map[r][c] + std::min(sol(r - 1, c), sol(r, c - 1));
	}
};

int main()
{
	Problem().facade();

	return 0;
}