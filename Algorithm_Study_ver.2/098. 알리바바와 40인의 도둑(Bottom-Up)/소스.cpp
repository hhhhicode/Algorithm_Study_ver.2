// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda(auto), using, unique_ptr, try

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n;
	int res;
	int** map = nullptr;

public:
	~Problem()
	{
		for (int i = 0; i < _n + 1; i++)
			delete[] map[i];
		delete[] map;
	}
	void facade()
	{
		init();
		sol();
		std::cout << res;
	}
	void init()
	{
		auto makeMap = [this](const auto& _n) -> void
		{
			map = new int* [_n + 1];
			for (int i = 0; i < _n + 1; i++)
				map[i] = new int[_n + 1]();
			for (int i = 1; i < _n + 1; i++)
				for (int j = 1; j < _n + 1; j++)
					std::cin >> map[i][j];
		};

		try
		{
			std::cin >> _n;
			makeMap(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		int right{ 0 };
		int down{ 0 };
		for (int i = 1; i < _n + 1; i++)
			for (int j = 1; j < _n + 1; j++)
			{
				if (i == 1) map[i][j] = map[i][j - 1] + map[i][j];
				else if (j == 1) map[i][j] = map[i - 1][j] + map[i][j];
				else
				{
					right = map[i][j - 1] + map[i][j];
					down = map[i - 1][j] + map[i][j];
					map[i][j] = right < down ? right : down;
				}
			}

		res = map[_n][_n];
	}
};

int main()
{
	Problem().facade();

	return 0;
}