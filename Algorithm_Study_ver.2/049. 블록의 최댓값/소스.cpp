// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// using, unique_ptr, try

#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	std::unique_ptr<myUnique[]> block = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << sumBlock();
	}
	void init()
	{
		try
		{
			std::cin >> _n;
			block = std::make_unique<myUnique[]>(_n);
			for (int i = 0; i < _n; i++)
				block[i] = std::make_unique<int[]>(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	void solution()
	{
		for (int j = 0; j < _n; j++)
		{
			int tmp;
			std::cin >> tmp;
			for (int i = 0; i < _n; i++)
			{
				block[i][j] = tmp;
			}
		}
		for (int i = 0; i < _n; i++)
		{
			int tmp;
			std::cin >> tmp;
			for (int j = 0; j < _n; j++)
			{
				block[i][j] = block[i][j] >= tmp ? tmp : block[i][j];
			}
		}
	}
	int sumBlock()
	{
		int sum(0);
		for (int i = 0; i < _n; i++)
		{
			for (int j = 0; j < _n; j++)
			{
				sum += block[i][j];
			}
		}
		return sum;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}