// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// using, unique_ptr, try
#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _m;
	int count{ 0 };
	std::unique_ptr<myUnique[]> nodes = nullptr;
	myUnique ch = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << count;
	}
	void init()
	{
		try
		{
			std::cin >> _n >> _m;
			nodes = std::make_unique<myUnique[]>(_n + 1);
			for (int i = 1; i <= _n; i++)
			{
				nodes[i] = std::make_unique<int[]>(_n + 1);
			}
			for (int i = 0, v1, v2; i < _m; i++)
			{
				std::cin >> v1 >> v2;
				nodes[v1][v2] = 1;
			}

			ch = std::make_unique<int[]>(_n + 1);
			ch[1] = 1;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(const int& v2 = 1)
	{
		if (v2 == _n)
		{
			count++;
			return;
		}
		else
		{
			for (int j = 1; j <= _n; j++)
			{
				if (nodes[v2][j] == 1 && ch[j] == 0)
				{
					ch[j] = 1;
					solution(j);
					ch[j] = 0;
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