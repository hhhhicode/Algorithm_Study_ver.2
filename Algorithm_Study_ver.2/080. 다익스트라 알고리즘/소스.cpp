// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try


// unique_ptr에 vector를 template parameter로 사용하면, 
// capacity가 0이어서 push_back때 메모리가 해제되고 재생성되므로 unique_ptr과 충돌이 있는 것 같다.
// 아닌가..? unique_ptr 빼도 오류나네.
// 아닌 것 같다... 모르겠다. 메모리 오류...
// resize때도 오류가 뜬다. 아마 vector를 배열로 잡았고, capacity가 0이고, 재할당 하는데 포인터 문제가 있는 것 같다.

// 아니다 해보니까 Edge가 클래스라서 문제였다.  vector<_T>의 _T에 class가 들어갔었는데, 그게 메모리상에서 문제가 있었다.
// struct로 하니까 된다. class와 struct의 차이...?

// int의 max에 +가 되어서 오버플로우로 -가 되었기 때문에 문제가 있었다.
// max값에는 수식이 없도록 하는게 좋겠다.

#include <iostream>
#include <vector>
#include <tuple>

class Edge
{
private:
	int target;
	int cost;

public:
	Edge() {};
	Edge(const int& t, const int& c)
		: target(t), cost(c)
	{}


	std::tuple<int, int> getTuple()
	{
		return std::tuple(target, cost);
	}
};

class Problem
{
	using dTT = std::unique_ptr<int[]>;
private:
	int _n, _m;		// n : 정점 개수, m : 
	dTT dis = nullptr;
	std::vector<Edge>* edge = nullptr;
	

public:
	void facade()
	{
		init();
		solution();
		printRes();
	}
	void init()
	{
		auto makeDistanceTable = [this]()
		{
			dis = std::make_unique<int[]>(_n + 1);
			for (int i = 0; i <= _n; i++)
				dis[i] = std::numeric_limits<int>::max();
			dis[1] = 0;
		};
		auto makeEdge = [this]()
		{
			edge = new std::vector<Edge>[_n + 1];
			for (int i = 0, v1, v2, cost; i < _m; i++)
			{
				std::cin >> v1 >> v2 >> cost;
				// edge[v1].push_back(Edge(v2, cost));
				edge[v1].emplace_back(Edge(v2, cost));
			}
		};

		try
		{
			std::cin >> _n >> _m;
			makeDistanceTable();
			makeEdge();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void solution()
	{
		for (int i = 1; i <= _n; i++)
		{
			for (auto e : edge[i])
			{
				auto [target, cost] = e.getTuple();
				// int의 max에 +가 되어서 오버플로우로 -가 되었기 때문에 문제가 있었다.
				// max값에는 수식이 없도록 하는게 좋겠다.
				dis[target] = dis[target] - cost > dis[i] ? dis[i] + cost : dis[target];
			}
		}
	}

	void printRes()
	{
		for (int i = 2; i <= _n; i++)
		{
			std::cout << i << " : ";
			if (dis[i] != std::numeric_limits<int>::max())
				std::cout << dis[i] << std::endl;
			else std::cout << "impossible\n";
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}