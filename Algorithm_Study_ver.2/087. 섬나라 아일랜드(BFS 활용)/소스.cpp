// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, try

#include <iostream>
#include <queue>

using cir = const int&;

struct Position
{
	int _r, _c;

	Position(cir r, cir c)
		: _r(r), _c(c)
	{}
	Position(const Position& p)
	{
		_r = p._r;	_c = p._c;
	}
};

class Problem
{
	using myUniqueIntArr = std::unique_ptr<int[]>;
private:
	int _n;
	int _count;
	std::unique_ptr<myUniqueIntArr[]> map = nullptr;
	std::queue<Position> q;

public:
	void facade()
	{
		init();
		sol();
		std::cout << _count;
	}
	void init()
	{
		auto makeMap = [this](const auto& _n) -> void
		{
			map = std::make_unique<myUniqueIntArr[]>(_n + 1);
			for (int i = 1; i < _n + 1; i++)
				map[i] = std::make_unique<int[]>(_n + 1);
			for (int i = 1; i < _n + 1; i++)
				for (int j = 1; j < _n + 1; j++)
					std::cin >> map[i][j];
		};

		try
		{
			std::cin >> _n;
			makeMap(_n);
			_count = 0;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void BFS(cir r, cir c)
	{
		int rl[] = {-1, -1, 0, 1, 1, 1, 0, -1};
		int cl[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
		map[r][c] = 0;
		q.push(Position(r, c));
		
		while (!q.empty())
		{
			auto here = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				auto thereR = here._r + rl[i];
				auto thereC = here._c + cl[i];
				if (1 <= thereR && thereR <= _n && 1 <= thereC && thereC <= _n && map[thereR][thereC] == 1)
				{
					map[thereR][thereC] = 0;
					q.push(Position(thereR, thereC));
				}
			}
		}
	}
	void sol()
	{
		for (int i = 1; i < _n + 1; i++)
			for (int j = 1; j < _n + 1; j++)
				if (map[i][j] == 1)
				{
					_count++;
					BFS(i, j);
				}
	}
};

int main()
{
	Problem().facade();

	return 0;
}