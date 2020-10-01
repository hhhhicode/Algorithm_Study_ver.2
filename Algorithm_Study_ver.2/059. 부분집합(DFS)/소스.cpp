// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, using, unique_pr, try
#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	myUnique nums = nullptr;

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
			std::cin >> _n;
			nums = std::make_unique<int[]>(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(const int& index = 0)
	{
		auto printNums = [this]()
		{
			for (int i = 0; i < _n; i++)
			{
				if (nums[i] != 0)
					std::cout << nums[i] << ' ';
			}
			std::cout << std::endl;
		};

		if (index >= _n)
		{
			printNums();
			return;
		}
		else
		{
			// 사용될 때 dfs
			nums[index] = index + 1;
			solution(index + 1);
			
			// 사용 안될 때 dfs
			nums[index] = 0;
			solution(index + 1);
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}