// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr, try
// auto, lambda, using, unique_ptr, try
#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	std::unique_ptr<myUnique[]> map;

public:
	void facade()
	{
		init();
		std::cout << searchMountin();
	}
	void init()
	{
		try
		{
			std::cin >> _n;
			map = std::make_unique<myUnique[]>(_n + 2);
			for (int i = 0; i <= _n + 1; i++)
				map[i] = std::make_unique<int[]>(_n + 2);

			for (int i = 1; i <= _n; i++)
				for (int j = 1; j <= _n; j++)
					std::cin >> map[i][j];
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	int searchMountin()
	{
		auto counter = [this](const int& i, const int& j, int xl[], int yl[]) -> bool
		{
			for (int l = 0; l < 4; l++)
			{
				if (map[i][j] <= map[i + xl[l]][j + yl[l]])
					return false;
			}
			return true;
		};

		int xl[4]{ -1, 0, 1, 0 };
		int yl[4]{0, 1, 0, -1};

		int count(0);
		for (int i = 1; i <= _n; i++)
			for (int j = 1; j <= _n; j++)
				if (counter(i, j, xl, yl))
					count++;
		return count;
	}

	void printMap()
	{
		for (int i = 0; i <= _n + 1; i++)
		{
			for (int j = 0; j <= _n + 1; j++)
			{
				std::cout << map[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}