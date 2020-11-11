// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>
#include <queue>
#include <vector>

using cir = const int&;

class Job
{
private:
	friend class Problem;
	int v1, v2;
public:
	Job() {}
	Job(cir v1, cir v2)
		: v1(v1), v2(v2)
	{}
};

class Problem
{
private:
	int _n, _m;
	std::queue<int> q;
	std::unique_ptr<int[]> waitingList = nullptr;
	std::vector<int>* adj = nullptr;
public:
	void facade()
	{
		init();
		sol();
	}
	void init()
	{
		auto makePlan = [this](cir n, cir m)
		{
			adj = new std::vector<int>[n + 1];
			waitingList = std::make_unique<int[]>(n + 1);
			for (int i = 0, v1, v2; i < m; i++)
			{
				std::cin >> v1 >> v2;
				waitingList[v2]++;
				adj[v1].push_back(v2);
			}
			for (int i = 1; i < n + 1; i++)
				q.push(i);
		};

		try
		{
			std::cin >> _n >> _m;
			makePlan(_n, _m);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		while (!q.empty())
		{
			auto& here = q.front();
			if (waitingList[here] == 0)
			{
				std::cout << here << ' ';
				for (const auto& a : adj[here])
					waitingList[a]--;
				q.pop();

			}
			else
			{
				q.push(q.front());
				q.pop();
			}
		}
	}
};

int main()
{
	Problem().facade();

	return 0;
}