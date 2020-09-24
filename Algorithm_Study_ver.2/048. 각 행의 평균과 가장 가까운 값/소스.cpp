// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, tuple, using, unique_ptr, try


#include <iostream>
#include <limits>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	std::unique_ptr<myUnique[]> list = nullptr;
	myUnique avgList = std::make_unique<int[]>(9);

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		try
		{
			list = std::make_unique<myUnique[]>(9);
			for (int i = 0; i < 9; i++)
			{
				list[i] = std::make_unique<int[]>(9);
				int sum(0);
				for (int j = 0; j < 9; j++)
				{
					std::cin >> list[i][j];
					sum += list[i][j];
				}
				avgList[i] = int(sum / 9.0 + 0.5);
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	void solution()
	{
		using myTuple = std::tuple<int, int>;
		using cIntR = const int&;
		auto searchMin = [this](myTuple& value_min, cIntR tmp, cIntR i, cIntR j) -> void
		{
			
			if (std::get<1>(value_min) > tmp)
				value_min = std::tuple(list[i][j], tmp);
		};
		auto ifEqual = [this](myTuple& value_min, cIntR tmp, cIntR i, cIntR j) -> void
		{

			if (std::get<1>(value_min) == tmp)
				if (list[i][j] > std::get<0>(value_min))
					value_min = std::tuple(list[i][j], tmp);
		};

		for (int i = 0; i < 9; i++)
		{
			auto value_min = std::tuple(0, std::numeric_limits<int>::max());
			for (int j = 0; j < 9; j++)
			{
				int tmp(std::abs(avgList[i] - list[i][j]));
				searchMin(value_min, tmp, i, j);
				ifEqual(value_min, tmp, i, j);				
			}
			std::cout << avgList[i] << ' ' << std::get<0>(value_min) << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}