// 비효율적으로 푼 문제. 사실상 틀린 문제.
// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>
#include <queue>

using cir = const int&;

class Position2D
{
private:
	int _r, _c;
	int _dis = 0;

public:
	bool operator < (const Position2D& p2) const
	{
		if (_dis == p2._dis)
		{
			if (_r == p2._r)
				return _c > p2._c;
			else
				return _r > p2._r;
		}
		else
			return _dis > p2._dis;		
	}
	Position2D()
		: _r(0), _c(0)
	{}
	Position2D(cir r, cir c, cir d = 0)
		: _r(r), _c(c), _dis(d)
	{}
	Position2D(const Position2D& pos)
		: _r(pos._r), _c(pos._c), _dis(pos._dis)
	{}
	int& getR()
	{
		return _r;
	}
	int& getC()
	{
		return _c;
	}
	int& getDis()
	{
		return _dis;
	}
};

class Simba
{
private:
	Position2D* pos = nullptr;
	int size;
	int eat;

public:
	Simba()
		: size(2), eat(0)
	{}
	Simba(cir r, cir c)
		: size(2), eat(0), pos(new Position2D(r, c))
	{}
	void eater(cir r, cir c)
	{
		if (++eat == size) // 잘 돌아가려나?
		{
			size++;
			eat = 0;
		}
		setPosition(r, c);
	}
	int& getSize()
	{
		return size;
	}
	void setPosition(cir r, cir c)
	{
		if (pos != nullptr)
			delete pos;
		pos = new Position2D(r, c);
	}
	Position2D*& getPosition()
	{
		return pos;
	}
};

class Problem
{
	using myUniqueIntArr = std::unique_ptr<int[]>;
private:
	int _n;
	int time;
	std::unique_ptr<myUniqueIntArr[]> jungle = nullptr;
	std::unique_ptr<myUniqueIntArr[]> check = nullptr;
	Simba* simba = nullptr;
	std::priority_queue<Position2D> q; // 거리 더해주는것 check에 수정하기.

	void reset()
	{
		for (int i = 0; i < _n; i++)
			for (int j = 0; j < _n; j++)
				check[i][j] = 0;
		while (!q.empty())
			q.pop();
	}

public:
	void facade()
	{
		init();
		sol();
		std::cout << time;
	}
	void init()
	{
		auto makeJungle = [this](const auto& n) -> void
		{
			jungle = std::make_unique<myUniqueIntArr[]>(n);
			for (int i = 0; i < n; i++)
			{
				jungle[i] = std::make_unique<int[]>(n);
				for (int j = 0; j < n; j++)
				{
					std::cin >> jungle[i][j];
					if (jungle[i][j] == 9)
						simba = new Simba(i, j);
				}
			}
		};
		auto makeCheck = [this](const auto& n) -> void
		{
			check = std::make_unique<myUniqueIntArr[]>(n);
			for (int i = 0; i < n; i++)
				check[i] = std::make_unique<int[]>(n);
		};


		try
		{
			std::cin >> _n;
			makeJungle(_n);
			makeCheck(_n);
			time = 0;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		// 먹을 수 있는 토끼 찾기 1) 사이즈 작음 2) 가장 가까움 2-1) 가장 위 2-2) 가장 왼쪽 
		// 3) 사이즈 같으면 지나감
		// 토끼 찾는거에서 맨날 막히네... ㅅㅂ
		
		int rl[4] = { -1, 0, 0, 1 }; // 위 왼 우 아래
		int cl[4] = { 0, -1, 1, 0 };
		auto& simbaHere = simba->getPosition();
		q.push(Position2D(simbaHere->getR(), simbaHere->getC()));
		check[simbaHere->getR()][simbaHere->getC()] = 1;
		jungle[simbaHere->getR()][simbaHere->getC()] = 0;

		while (!q.empty())
		{
			auto here = q.top();	q.pop();

			if (0 < jungle[here.getR()][here.getC()] && jungle[here.getR()][here.getC()] < simba->getSize())
			{
				time = here.getDis();
				jungle[here.getR()][here.getC()] = 0;
				simba->eater(here.getR(), here.getC());
				//std::cout << thereR << ' ' << thereC << ' ' << simba->getSize() << std::endl;
				reset();
				q.push(Position2D(simbaHere->getR(), simbaHere->getC(), here.getDis()));
			}

			for (int i = 0; i < 4; i++)
			{
				int thereR = here.getR() + rl[i];
				int thereC = here.getC() + cl[i];

				if (0 <= thereR && thereR < _n && 0 <= thereC && thereC < _n)
				{
					if (simba->getSize() >= jungle[thereR][thereC] || jungle[thereR][thereC] == 0)
					{
						if (check[thereR][thereC] == 0)
						{
							check[thereR][thereC] = 1;
							q.push(Position2D(thereR, thereC, here.getDis() + 1));
						}
					}
				}
			}
		}
	}
	
};

int main()
{
	Problem().facade();

	return 0;
}