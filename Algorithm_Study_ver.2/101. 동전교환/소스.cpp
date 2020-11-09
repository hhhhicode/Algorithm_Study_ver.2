// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using,unique_ptr, try

#include <iostream>
#include <algorithm>

using cir = const int&;

class Problem
{
	using myUniqueIntArr = std::unique_ptr<int[]>;
private:
	int _n, _m;
	myUniqueIntArr coinCategory = nullptr;
	myUniqueIntArr changeCoin = nullptr;
public:
	void facade()
	{
		init();
		std::cout << sol();
	}

	void init()
	{
		auto makeCoinCategory = [this](cir n) -> void
		{
			coinCategory = std::make_unique<int[]>(n);
			for (int i = 0; i < n; i++)
				std::cin >> coinCategory[i];
		};
		auto makeChangeCoin = [this](cir _m) -> void
		{
			changeCoin = std::make_unique<int[]>(_m + 1);
			for (int i = 1; i < _m + 1; i++)
				changeCoin[i] = std::numeric_limits<int>::max();
		};

		try
		{
			std::cin >> _n;
			makeCoinCategory(_n);
			std::cin >> _m;
			makeChangeCoin(_m);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int sol()
	{
		for (int i = 0; i < _n; i++)
			for (int j = coinCategory[i]; j < _m + 1; j++)
				changeCoin[j] = std::min(changeCoin[j], changeCoin[j - coinCategory[i]] + 1);
		return changeCoin[_m];
	}
};

int main()
{
	Problem().facade();

	return 0;
}