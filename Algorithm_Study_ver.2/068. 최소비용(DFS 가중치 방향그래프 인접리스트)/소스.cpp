// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, pair, using, unique_ptr, try

#include <iostream>
#include <vector>

class Problem
{
	using myVec = std::vector<std::pair<int, int> >;
	using myCheck = std::unique_ptr<bool[]>;
private:
	int _n, _m;
	int minCost{ std::numeric_limits<int>::max() };
	myCheck ch = nullptr;
	myVec* adjList;

public:
	void facade()
	{
		init();
		solution();
		std::cout << minCost;
	}
	void init()
	{
		auto makeAdjList = [this]() -> void
		{
			adjList = new myVec[_n + 1];
			for (int v1, v2, value, i = 0; i < _m; i++)
			{
				std::cin >> v1 >> v2 >> value;
				adjList[v1].push_back(std::make_pair(v2, value));
			}
		};
		auto makeCheckList = [this]() -> void
		{
			ch = std::make_unique<bool[]>(_n + 1);
			ch[1] = true;
		};

		try
		{
			std::cin >> _n >> _m;
			makeAdjList();
			makeCheckList();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(const int& n = 1, const int& costSum = 0)
	{
		if (n == _n)
		{
			minCost = minCost > costSum ? costSum : minCost;
			return;
		}
		else
		{
			int there, cost;
			for (auto p : adjList[n])
			{
				there = p.first;	cost = p.second;
				if (ch[there] == false)
				{
					ch[there] = true;
					solution(there, costSum + cost);
					ch[there] = false;
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