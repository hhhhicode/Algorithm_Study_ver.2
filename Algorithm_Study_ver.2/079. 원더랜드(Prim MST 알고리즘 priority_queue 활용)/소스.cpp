// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, tuple, using, unique_ptr, try

#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

class Edge
{
private:
	int target;
	int cost;

public:
	Edge(const int& t, const int& c)
	{
		target = t;
		cost = c;
	}

	bool operator < (const Edge& e) const
	{
		return this->cost > e.cost;
	}

	std::tuple<int, int> getEdge() const
	{
		return std::tuple(this->target, this->cost);
	}
};

class Problem
{
	using myCheck = std::unique_ptr<bool[]>;
	using myVec = std::unique_ptr<std::vector<Edge>[]>;
private:
	int _v, _e;	// v : ���� ����, e : ���� ����
	int sum{ 0 };
	myCheck ch = nullptr;
	std::priority_queue<Edge> pQ;
	myVec v;

public:
	void facade()
	{
		init();
		solution();
		std::cout << sum;
	}
	void init()
	{
		auto makeCheckList = [this]() -> void
		{
			ch = std::make_unique <bool[]>(_v + 1);
		};
		auto makeEdge = [this]() -> void
		{
			v = std::make_unique<std::vector<Edge>[]>(_v + 1);
			for (int i = 0; i < _e; i++)
			{
				int v1, v2, cost;
				std::cin >> v1 >> v2 >> cost;
				v[v1].push_back(Edge(v2, cost));
				// �־����°� ���� ���⿡ ���ؼ��� �־����� ����� �׷����ϱ� �� �� ����� ��𼭵� ������ �� �� �ִ�.
				v[v2].push_back(Edge(v1, cost));	
			}
		};

		try
		{
			std::cin >> _v >> _e;
			makeCheckList();
			makeEdge();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution()
	{
		pQ.push(Edge(1, 0));

		while (!pQ.empty())
		{
			auto [target, cost] = pQ.top().getEdge();	// .top()�� cost ����, .getEdge()�� cost�� ���־���.
			pQ.pop();

			if (ch[target] != true)
			{
				ch[target] = true;
				sum += cost;

				for (auto edge : v[target])
					pQ.push(edge);
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