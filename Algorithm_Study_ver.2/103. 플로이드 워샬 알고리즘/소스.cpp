// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n, _m;
	std::unique_ptr<std::unique_ptr<int[]>[]> cost = nullptr;
	
public:
	void facade()
	{
		init();
		sol();
		printRes();
	}
	void init()
	{
		auto makeAdjAndCostArr = [this](cir n, cir m) -> void
		{
			cost = std::make_unique<std::unique_ptr<int[]>[]>(n + 1);
			for (int i = 0; i < n + 1; i++)
				cost[i] = std::make_unique<int[]>(n + 1);
			for (int i = 1; i < n + 1; i++)
				for (int j = 1; j < n + 1; j++)
				{
					if (i == j) cost[i][j] = 0;
					else
						cost[i][j] = std::numeric_limits<int>::max();
				}
			for (int i = 0, v1, v2, c; i < m; i++)
			{
				std::cin >> v1 >> v2 >> c;
				cost[v1][v2] = c;
			}
		};

		try
		{
			std::cin >> _n >> _m;
			makeAdjAndCostArr(_n, _m);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		for (int passNode = 1; passNode < _n + 1; passNode++)
			for (int v1 = 1; v1 < _n + 1; v1++)
				for (int v2 = 1; v2 < _n + 1; v2++)
					if (cost[v1][passNode] != std::numeric_limits<int>::max() && cost[passNode][v2] != std::numeric_limits<int>::max())
						cost[v1][v2] = cost[v1][v2] < cost[v1][passNode] + cost[passNode][v2] ?
						cost[v1][v2] : cost[v1][passNode] + cost[passNode][v2];
	}
	void printRes()
	{
		for (int i = 1; i < _n + 1; i++)
		{
			for (int j = 1; j < _n + 1; j++)
			{
				if (cost[i][j] == std::numeric_limits<int>::max()) std::cout << "M ";
				else
					std::cout << cost[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	Problem().facade();

	return 0;
}