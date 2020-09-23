// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr, try
// template, auto, lambda, tuple, using, try
#include <iostream>
#include <queue>
#include <tuple>

template<class myTuple>
class Problem
{
private:
	int _n, _k;
	std::queue<myTuple> q;

public:
	void facade()
	{
		init();
		run();
	}
	void init()
	{
		try
		{
			std::cin >> _n;
			for (int i = 1; i <= _n; i++)
			{
				int tmp;
				std::cin >> tmp;
				q.push(std::make_tuple(i, tmp));
			}
			std::cin >> _k;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	void run()
	{
		auto countDownFunction = [this]() -> bool
		{
			int countDown(_k);
			while (countDown-- != 0)
			{
				auto [a, b] = q.front();
				if (b - 1 != 0)
				{
					q.push(std::make_tuple(a, b - 1));
					q.pop();
				}
				else
					q.pop();

				if (q.empty())
					return false;
			}
			return true;
		};
		
		if (countDownFunction())
			std::cout << std::get<0>(q.front());
		else
			std::cout << -1;
	}
};

int main()
{
	using namespace std;
	using myTuple = std::tuple<int, int>;

	Problem<myTuple>().facade();

	return 0;
}