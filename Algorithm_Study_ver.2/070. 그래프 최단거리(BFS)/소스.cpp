// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>
#include <queue>
#include <vector>

class Problem
{
	using myVec = std::vector<int>;
	using myQueue = std::queue<int>;
	using myUnique = std::unique_ptr<int[]>;
private:
	myVec* v;
	myQueue q;
	myUnique dis = nullptr;
	int _n, _m;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		auto makeAdjList = [this]()
		{
			v = new myVec[_n + 1];
			for (int v1 = 0, v2 = 0, i = 0; i < _m; i++)
			{
				std::cin >> v1 >> v2;
				v[v1].push_back(v2);
			}
		};
		auto makeDis = [this]()
		{
			dis = std::make_unique<int[]>(_n + 1);
		};

		try
		{
			std::cin >> _n >> _m;
			makeAdjList();
			makeDis();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void printDis()
	{
		for (int i = 2; i <= _n; i++)
		{
			std::cout << i << " : " << dis[i] << std::endl;
		}
	}
	void solution()
	{
		using cir = const int&;
		auto pushChilds = [this](cir here) -> void
		{
			for (auto there : v[here])
			{
				if (dis[there] == 0)
				{
					q.push(there);
					dis[there] = dis[here] + 1;
				}
			}
		};

		q.push(1);
		
		int here{ 0 };
		while (!q.empty())
		{
			here = q.front();	q.pop();
			
			pushChilds(here);
		}

		dis[1] = 0;
		printDis();
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}