// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr
#include <iostream>

class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> list;

public:
	void facade()
	{
		init();
		run();
	}
	void init()
	{
		std::cin >> _n;
		list = std::make_unique<int[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}

	void run()
	{
		auto check = [&](const int& index) -> int
		{
			int count = index + 1;
			for (int i = 0; i < index; i++)
			{
				if (list[i] < list[index])
					count--;
			}
			return count;
		};

		for (int i = 0; i < _n; i++)
		{
			std::cout << check(i) << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}