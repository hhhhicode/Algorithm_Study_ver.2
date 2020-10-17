// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, tuple, using, unique_ptr, try

#include <iostream>
#include <vector>
#include <tuple>

using cir = const int&;
using myCost = std::unique_ptr<int[]>;

class Edge
{
private:
	int v1, v2, cost;

public:
	Edge() {};
	Edge(cir v1, cir v2, cir cost)
		: v1(v1), v2(v2), cost(cost) {}
	Edge(const Edge& e)
	{
		v1 = e.v1;
		v2 = e.v2;
		cost = e.cost;
	}
	std::tuple<int, int, int> getTuple() const
	{
		return std::tuple(v1, v2, cost);
	}
};

class Problem
{
private:
	int _n, _m;	// _n : 도시의 수, _m : 도로 수
	int start, end;	// start : 출발 도시, end : 도착 도시
	std::vector<Edge> edges;
	myCost costArr = nullptr;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		auto makeEdgeArr = [this](cir _m) -> void
		{
			for (int i = 0, v1, v2, cost; i < _m; i++)
			{
				std::cin >> v1 >> v2 >> cost;
				edges.emplace_back(v1, v2, cost);
			}
		};
		auto makeCostArr = [this](cir _n, cir start) -> void
		{
			costArr = std::make_unique<int[]>(_n + 1);
			for (int i = 1; i <= _n; i++)
				costArr[i] = std::numeric_limits<int>::max();
			costArr[start] = 0;
		};

		try
		{
			std::cin >> _n >> _m;
			makeEdgeArr(_m);
			std::cin >> start >> end;
			makeCostArr(_n, start);
		}
		catch(...)
		{
			std::cerr << "error";
		}
	}

	void solution()
	{
		auto updateCost = [this]() -> bool
		{
			bool isChange = false;
			for (const auto& e : edges)
			{
				const auto& [v1, v2, cost] = e.getTuple();
				if (costArr[v1] != std::numeric_limits<int>::max() && costArr[v2] > costArr[v1] + cost)
				{
					costArr[v2] = costArr[v1] + cost;
					isChange = true;
				}
			}
			return isChange;
		};

		for (int i = 0; i < _n - 1; i++)
			updateCost();

		if (updateCost() == true)
			std::cout << -1;
		else 
			std::cout << costArr[end];
	}
};

int main()
{
	using namespace std;

	Problem p;
	p.facade();

	return 0;
}