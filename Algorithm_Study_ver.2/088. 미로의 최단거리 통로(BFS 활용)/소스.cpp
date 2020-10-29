// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, try

#include <iostream>
#include <queue>

using cir = const int&;

class Position
{
private:
	int _r, _c;

public:
	Position()
		:_r(0), _c(0)
	{}
	Position(cir r, cir c)
		: _r(r), _c(c)
	{}
	int& getR()
	{
		return _r;
	}
	int& getC()
	{
		return _c;
	}
};

class Problem
{
	using myUniqueIntArr = std::unique_ptr<int[]>;
private:
	int _n;
	std::unique_ptr<myUniqueIntArr[]> map = nullptr;
	std::queue<Position> q;

public:
	void facade()
	{
		init();
		sol();
	}
	void init()
	{
		auto makeMap = [this](cir _n) -> void
		{
			map = std::make_unique<myUniqueIntArr[]>(_n + 1);
			for (int i = 1; i < _n + 1; i++)
			{
				map[i] = std::make_unique<int[]>(_n + 1);
				for (int j = 1; j < _n + 1; j++)
					std::cin >> map[i][j];
			}
		};

		try
		{
			std::cin >> _n;
			makeMap(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	
	void sol()
	{
		auto checkMap = [this](cir thereR, cir thereC) -> bool
		{
			if (1 <= thereR && thereR <= _n && 1 <= thereC && thereC <= _n)
				return true;
			return false;
		};

		int rl[4] = { 0, 1, 0, -1 };
		int cl[4] = { -1, 0, 1, 0 };

		q.push(Position(1, 1));

		while (!q.empty())
		{
			Position p = q.front(); q.pop();
			if (p.getR() == 7 && p.getC() == 7)
			{
				std::cout << map[7][7];
				return;
			}

			for (int l = 0; l < 4; l++)
			{
				int thereR = p.getR() + rl[l];
				int thereC = p.getC() + cl[l];

				if (checkMap(thereR, thereC) == true)
					if (map[thereR][thereC] == 0) {
						if (thereR == 1 && thereC == 1) continue;
						q.push(Position(thereR, thereC));
						map[thereR][thereC] = map[p.getR()][p.getC()] + 1;
					}
			}
		}
		
		std::cout << -1;
	}
};

int main()
{
	Problem().facade();

	return 0;
}