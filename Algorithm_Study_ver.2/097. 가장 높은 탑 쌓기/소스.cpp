// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, tru

#include <iostream>
#include <algorithm>

using cir = const int&;

class Block
{
private:
	int _square, _weight, _length;

public:
	friend class Problem;
	Block() {}
	Block(const int&& s, const int&& l, const int&& w)
		:_square(s), _length(l), _weight(w)
	{}

	bool operator < (const Block& b2) const
	{
		return _square > b2._square;
	}
};

class Problem
{
	using myUniqueBlockArr = std::unique_ptr<Block[]>;
private:
	int _n;
	int _res;
	myUniqueBlockArr blocks = nullptr;

public:
	void facade()
	{
		init();
		_res = sol();
		std::cout << _res;
	}
	void init()
	{
		auto makeBlock = [this](cir n)
		{
			blocks = std::make_unique<Block[]>(n);
			for (int i = 0, s, l, w; i < n; i++)
			{
				std::cin >> s >> l >> w;
				// move semantics를 이용한 move constructor // 레퍼런스가 더 좋을것이다.
				blocks[i] = Block(std::move(s), std::move(l), std::move(w));
			}
		};

		try
		{
			std::cin >> _n;
			makeBlock(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int sol()
	{
		std::unique_ptr<int[]> sumLength(new int[_n]);
		// sort 후 인덱스별로 접근하면 면적은 신경쓰지 않아도 된다.
		std::sort(&blocks[0], &blocks[_n]);

		for (int i = 0; i < _n; i++)
		{
			sumLength[i] = blocks[i]._length;
			for(int j = 0; j < i; j++)
				if (blocks[i]._weight < blocks[j]._weight)
					sumLength[i] = sumLength[i] < sumLength[j] + blocks[i]._length ?
					sumLength[j] + blocks[i]._length : sumLength[i];
		}

		int max = 0;
		for (int i = 0; i < _n; i++)
			max = max < sumLength[i] ? sumLength[i] : max;
		return max;
	}
};

int main()
{
	Problem().facade();

	return 0;
}