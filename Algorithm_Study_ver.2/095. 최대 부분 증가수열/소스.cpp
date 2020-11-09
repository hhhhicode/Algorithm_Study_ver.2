// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda, using, unique_ptr, try

#include <iostream>

using cir = const int&;
using myUniqueIntArr = std::unique_ptr<int[]>;

class Problem
{
private:
	int _n;
	int res;
	myUniqueIntArr nums = nullptr;
	myUniqueIntArr lengthCheck = nullptr;

public:
	void facade()
	{
		init();
		sol();
		std::cout << res;
	}
	void init()
	{
		auto makeNumsAndCheckArr = [this](cir n)
		{
			nums = std::make_unique<int[]>(n);
			lengthCheck = std::make_unique<int[]>(n);
			for (int i = 0; i < n; i++)
			{
				std::cin >> nums[i];
				lengthCheck[i] = 1;
			}
		};

		try
		{
			res = 0;
			std::cin >> _n;
			makeNumsAndCheckArr(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		auto lengthRelax = [this](cir i)
		{
			for (int index = 0; index < i; index++)
				if (nums[index] < nums[i])
					lengthCheck[i] = lengthCheck[i] < lengthCheck[index] + 1 ? lengthCheck[index] + 1 : lengthCheck[i];
		};
		auto searchMax = [this](cir n)
		{
			for (int i = 0; i < n; i++)
				res = res < lengthCheck[i] ? lengthCheck[i] : res;
		};

		for (int i = 0; i < _n; i++)
			lengthRelax(i);

		searchMax(_n);
	}
};

int main()
{
	Problem().facade();

	return 0;
}