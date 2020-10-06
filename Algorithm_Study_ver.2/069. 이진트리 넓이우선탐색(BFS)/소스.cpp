// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, try

#include <iostream>
#include <queue>
#include <vector>

class Problem
{
private:
	int _m;
	std::vector<int> v[8];
	std::queue<int> q;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		auto makeTree = [this]()
		{
			for (int v1, v2, i = 0; i < 6; i++)
			{
				std::cin >> v1 >> v2;
				v[v1].push_back(v2);
			}
		};
		
		try
		{
			makeTree();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void solution()
	{
		using cir = const int&;
		auto pushChilds = [this](cir here)
		{
			for (auto there : v[here])
				q.push(there);
		};

		q.push(1);
		int here{ 0 };
		while (!q.empty())
		{
			here = q.front();	q.pop();
			std::cout << here << ' ';
			
			pushChilds(here);
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}