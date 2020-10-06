// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, try

#include <iostream>
#include <queue>

class Problem
{
	using myQ = std::queue<int>;
private:
	int dis[10001]{};
	int _s, _e; // s : 현수 위치, e : 송아지 위치
	myQ q;

public:
	void facade()
	{
		init();
		solution();
		std::cout << dis[_e];
	}
	void init()
	{
		try
		{
			std::cin >> _s >> _e;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution()
	{
		auto pushMove = [this](const int& here, const int move[]) -> void
		{
			int there;
			for (int i = 0; i < 3; i++)
			{
				there = here + move[i];
				if (dis[there] == 0 && 1 <= there && there <= 10000)
				{
					dis[there] = dis[here] + 1;
					q.push(there);
				}
			}
		};

		q.push(_s);
		int move[]{ -1,1,5 };
		int here{ 0 };
		while (!q.empty())
		{
			here = q.front();	q.pop();
			if (here == _e)
				return;
			else
			{
				pushMove(here, move);
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