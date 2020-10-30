// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda(auto), pair, using, try

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
	std::pair<int, int> getPosition()
	{
		return std::make_pair(_r, _c);
	}
};

class Problem
{
private:
	int _N, _M;
	int** box = nullptr;
	std::queue<Position> q;

public:
	Problem()
	{
		init();
	}
	~Problem()
	{
		for (int i = 0; i < _N; i++)
			delete box[i];
		delete box;
	}
	void facade()
	{
		BFS();
	}
	void init()
	{
		auto makeBox = [this](auto N, auto M)
		{
			box = new int* [N];
			for (int i = 0; i < N; i++)
			{
				box[i] = new int[M];
				for (int j = 0; j < M; j++)
				{
					std::cin >> box[i][j];
					if (box[i][j] == 1)
						q.push(Position(i, j));
				}
			}
		};

		try
		{
			std::cin >> _M >> _N;
			makeBox(_N, _M);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void BFS()
	{
		auto checkBox = [this](cir R, cir C) -> bool
		{
			if (0 <= R && R < _N && 0 <= C && C < _M)
				return true;
			return false;
		};
		auto allBoxOne = [this]() -> bool
		{
			for (int i = 0; i < _N; i++)
				for (int j = 0; j < _M; j++)
					if (box[i][j] == 0)
						return false;
			return true;
		};

		int rl[4] = { 0, 1, 0, -1 };
		int cl[4] = { -1, 0, 1, 0 };
		std::pair<int, int> here;
		while (!q.empty())
		{
			here = q.front().getPosition(); q.pop();

			for (int i = 0; i < 4; i++)
			{
				int thereR = here.first + rl[i];
				int thereC = here.second + cl[i];

				if (checkBox(thereR, thereC) == true)
					if (box[thereR][thereC] == 0)
					{
						box[thereR][thereC] = box[here.first][here.second] + 1;
						q.push(Position(thereR, thereC));
					}
			}
		}
		if (allBoxOne() == true)
			std::cout << box[here.first][here.second] - 1;
		else
			std::cout << -1;
	}
};

int main()
{
	Problem().facade();

	return 0;
}