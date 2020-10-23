// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda(auto), using, unique_ptr, try

#include <iostream>
#include <vector>

struct Position
{
	int _r, _c;
	Position()
	{
		_r = 0;
		_c = 0;
	}
	Position(const int& r, const int& c)
	{
		_r = r;
		_c = c;
	}
	Position(const Position& p)
	{
		_r = p._r;
		_c = p._c;
	}
};

class Problem
{
	using myVector = std::vector<Position>;
private:
	int _n, _m;
	int _minSumDistance;
	myVector home;
	myVector pizza;
	std::unique_ptr<Position[]> alivedPizza = nullptr;

public:
	void facade()
	{
		init();
		sol();
		std::cout << _minSumDistance;
	}
	void init()
	{
		auto makeCity = [this](const auto& _n) -> void
		{
			int tmp;
			for (int i = 1; i < _n + 1; i++)
				for (int j = 1; j < _n + 1; j++)
				{
					std::cin >> tmp;
					if (tmp == 1)
						home.push_back(Position(i, j));
					if (tmp == 2)
						pizza.push_back(Position(i, j));
				}
		};
		auto makeAlivedPizza = [this](const auto& _m) -> void
		{
			// Level마다 Position을 할당시킨다. alivedPizza모두 돌면서 거리 구하면 된다.
			// 존나 좋은 생각!!!
			alivedPizza = std::make_unique<Position[]>(_m);
		};

		try
		{
			std::cin >> _n >> _m;
			makeCity(_n);
			makeAlivedPizza(_m);
			_minSumDistance = std::numeric_limits<int>::max();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol(const int& L = 0, const int& r = 0)
	{
		static auto sumDistance = [this]() -> void
		{
			// 집들 각각에서 피자집까지의 최소를 합한것이 최종 최소 거리이다.
			// ㅅㅂ 이걸 ..이걸... 잘못 이해해서 다 더하고 앉았으니 나는 멍청한듯.
			int sum = 0;
			int dis;
			for (const auto & h : home)
			{
				int minDis = std::numeric_limits<int>::max();
				for (int p = 0; p < _m; ++p)
				{
					dis = std::abs(h._r - alivedPizza[p]._r) + std::abs(h._c - alivedPizza[p]._c);
					minDis = minDis > dis ? dis : minDis;
				}
				sum += minDis;
			}
			_minSumDistance = _minSumDistance > sum ? sum : _minSumDistance;
		};

		if (L == _m)
		{
			sumDistance();			
			return;
		}
		else
		{
			int index = r;
			for (; index < pizza.size(); ++index)
			{
				alivedPizza[L] = pizza[index];
				sol(L + 1, index + 1);
			}
		}
	}
	void printPosition()
	{
		for (int i = 0; i < _m; i++)
		{
			std::cout << alivedPizza[i]._r << " " << alivedPizza[i]._c << std::endl;
		}
		std::cout << std::endl;
	}

};

int main()
{
	Problem().facade();

	return 0;
}