// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try
#include <iostream>
#include <limits>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
	using ci = const int;
private:
	int _n, _m;
	int minCost{ std::numeric_limits<int>::max() };
	std::unique_ptr<myUnique[]> nodes = nullptr;
	myUnique checkList = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << minCost;
	}
	void init()
	{
		auto makeNodes = [this]()
		{
			nodes = std::make_unique<myUnique[]>(_n + 1);
			for (int i = 1; i <= _n; i++)
				nodes[i] = std::make_unique<int[]>(_n + 1);
			for (int i = 0, v1, v2; i < _m; i++)
			{
				std::cin >> v1 >> v2;
				std::cin >> nodes[v1][v2];
			}
		};
		auto makeCheckList = [this]() -> void
		{
			checkList = std::make_unique<int[]>(_n + 1);
			checkList[1] = 1;
		};
		
		try
		{
			std::cin >> _n >> _m;
			makeNodes();
			makeCheckList();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void solution(ci& n = 1, ci& cost = 0)
	{
		if (n == _n && minCost > cost)
		{
			minCost = cost;
			return;
		}
		else
		{
			for (int i = 1; i <= _n; i++)
			{
				if (nodes[n][i] != 0 && checkList[i] == 0)
				{
					checkList[i] = 1;
					solution(i, cost + nodes[n][i]);
					checkList[i] = 0;
				}
			}
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}