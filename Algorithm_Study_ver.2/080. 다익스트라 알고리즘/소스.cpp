// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try


// unique_ptr�� vector�� template parameter�� ����ϸ�, 
// capacity�� 0�̾ push_back�� �޸𸮰� �����ǰ� ������ǹǷ� unique_ptr�� �浹�� �ִ� �� ����.
// �ƴѰ�..? unique_ptr ���� ��������.
// �ƴ� �� ����... �𸣰ڴ�. �޸� ����...
// resize���� ������ ���. �Ƹ� vector�� �迭�� ��Ұ�, capacity�� 0�̰�, ���Ҵ� �ϴµ� ������ ������ �ִ� �� ����.

// �ƴϴ� �غ��ϱ� Edge�� Ŭ������ ��������.  vector<_T>�� _T�� class�� �����µ�, �װ� �޸𸮻󿡼� ������ �־���.
// struct�� �ϴϱ� �ȴ�. class�� struct�� ����...?

// int�� max�� +�� �Ǿ �����÷ο�� -�� �Ǿ��� ������ ������ �־���.
// max������ ������ ������ �ϴ°� ���ڴ�.

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
	int _n, _m;		// n : ���� ����, m : 
	dTT dis = nullptr;
	std::vector<Edge>* edge;
	

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
				edge[v1].push_back(Edge(v2, cost));
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
				// int�� max�� +�� �Ǿ �����÷ο�� -�� �Ǿ��� ������ ������ �־���.
				// max������ ������ ������ �ϴ°� ���ڴ�.
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