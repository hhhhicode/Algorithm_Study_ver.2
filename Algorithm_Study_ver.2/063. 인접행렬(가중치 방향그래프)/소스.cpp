// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// using, unique_ptr

#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _m; // _n : 정점의 수, _m : 간선의 수
	std::unique_ptr<myUnique[]> adj = nullptr;

public:
	void facade()
	{
		init();
		printAdj();
	}
	void init()
	{
		std::cin >> _n >> _m;
		adj = std::make_unique<myUnique[]>(_n + 1);
		for (int i = 1; i <= _n; i++)
			adj[i] = std::make_unique<int[]>(_n + 1);


		for (int i = 0, v1, v2, value; i < _m; i++)
		{
			std::cin >> v1 >> v2 >> value;
			adj[v1][v2] = value;
		}
	}
	void printAdj()
	{
		for (int i = 1; i <= _n; i++)
		{
			for (int j = 1; j <= _n; j++)
			{
				std::cout << adj[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}