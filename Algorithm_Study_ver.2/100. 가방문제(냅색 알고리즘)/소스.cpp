// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, try

#include <iostream>

using cir = const int&;

class Jewel
{
private:
	int _w, _v;

public:
	friend class Problem;
	Jewel() 
		:_w(0), _v(0)
	{}
	Jewel(cir w, cir v)
		:_w(w), _v(v)
	{}
};

class Problem
{
	using myUniqueJewelArr = std::unique_ptr<Jewel[]>;
	using myUniqueIntArr = std::unique_ptr<int[]>;
private:
	int _n, _w;
	myUniqueJewelArr jewels = nullptr;
	myUniqueIntArr bag = nullptr;
public:
	void facade()
	{
		init();
		std::cout << sol();
	}
	void init()
	{
		auto makeJewelAndBag = [this](const auto& n, const auto& w) -> void
		{
			jewels = std::make_unique<Jewel[]>(n);
			for (int i = 0, w, v; i < n; i++)
			{
				std::cin >> w >> v;
				jewels[i] = Jewel(w, v);
			}
			bag = std::make_unique<int[]>(w + 1);
		};

		try
		{
			std::cin >> _n >> _w;
			makeJewelAndBag(_n, _w);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int sol()
	{
		int thereValue;
		for (int i = 0; i < _n; i++)
		{
			for (int j = jewels[i]._w; j < _w + 1; j++)
			{
				thereValue = bag[j - jewels[i]._w] + jewels[i]._v;
				int& hereValue = bag[j];

				hereValue = hereValue < thereValue ? thereValue : hereValue;
			}
		}
		return bag[_w];
	}
};

int main()
{
	Problem().facade();

	return 0;
}