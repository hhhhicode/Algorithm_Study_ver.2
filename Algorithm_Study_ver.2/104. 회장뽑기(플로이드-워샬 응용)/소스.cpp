// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>

using cir = const int&;

class Problem
{
private:
	int _n;
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
		auto makeCost = [this](cir n)
		{
			cost = std::make_unique<std::unique_ptr<int[]>[]>(n + 1);
			for (int i = 1; i < n + 1; i++)
			{
				cost[i] = std::make_unique<int[]>(n + 1);
				for (int j = 1; j < n + 1; j++)
					cost[i][j] = std::numeric_limits<int>::max();
			}

			int v1 = 0, v2= 0;
			std::cin >> v1 >> v2;
			while (v1 != -1 && v2 != -1)
			{				
				cost[v1][v2] = 1;
				cost[v2][v1] = 1;
				std::cin >> v1 >> v2;
			}
		};
		try
		{
			std::cin >> _n;
			makeCost(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		const int& intInf = std::numeric_limits<int>::max();
		int min = _n;
		for (int mid = 1; mid < _n + 1; mid++)
			for (int v1 = 1; v1 < _n + 1; v1++)
				for (int v2 = 1; v2 < _n + 1; v2++)
				{
					const int& costFriend = cost[v1][mid] + cost[mid][v2];
					if (cost[v1][mid] != intInf && cost[mid][v2] != intInf)
						cost[v1][v2] = cost[v1][v2] < costFriend ? cost[v1][v2] : costFriend;
				}
	}
	void printRes()
	{
		std::unique_ptr<int[]> stu(new int[_n + 1]);
		int count = 0;
		int min = _n;
		for (int i = 1; i < _n + 1; i++)
		{
			int tmp = 0;
			for (int j = 1; j < _n + 1; j++)
			{
				tmp = tmp > cost[i][j] ? tmp : cost[i][j];
				stu[i] = tmp;
			}
			min = min < tmp ? min : tmp;
		}

		for (int i = 1; i < _n + 1; i++)
			if (stu[i] == min) count++;
		std::cout << min << ' ' << count << std::endl;

		for (int i = 1; i < _n + 1; i++)
			if (stu[i] == min) std::cout << i << ' ';
	}
};

int main()
{
	Problem().facade();

	return 0;
}