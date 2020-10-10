// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try

#include <iostream>
#include <algorithm>

class Edge
{
public:
	int v1, v2;
	int cost;

	bool operator < (const Edge& e)
	{
		return this->cost < e.cost;
	}
};

class Problem
{
	using myNode = std::unique_ptr<int[]>;
	using myEdge = std::unique_ptr<Edge[]>;
private:
	int _v, _e; // V : 도시의 개수, E : 도로의 개수
	myNode nodes = nullptr;
	myEdge edges = nullptr;

public:
	void facade()
	{
		init();
		sortEdgeByCost();
	}
	void init()
	{
		auto makeNode = [this]() -> void
		{
			nodes = std::make_unique<int[]>(_v + 1);
			for (int i = 1; i <= _v; i++)
				nodes[i] = i;
		};
		auto makeEdge = [this]()
		{
			edges = std::make_unique<Edge[]>(_e);
			for (int i = 0; i < _e; i++)
				std::cin >> edges[i].v1 >> edges[i].v2 >> edges[i].cost;
		};

		try
		{
			std::cin >> _v >> _e;
			makeNode();
			makeEdge();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sortEdgeByCost()
	{
		std::sort(&edges[0], &edges[_e]); // 되나?? 되냐?? ㅅㅂ 되냐??!?!?!?!
		std::cout << std::endl;
		for (int i = 0; i < _e; i++)
			std::cout << edges[i].cost << ' ';
		std::cout << std::endl;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}