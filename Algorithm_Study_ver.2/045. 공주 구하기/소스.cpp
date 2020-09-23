// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr, try
// auto, lambda, using, unique_ptr, try
#include <iostream>
#include <queue>

class Problem
{
	using myQueue = std::queue<int>;
private:
	int _n, _k; // n : 왕자의 수, k : 제외 번호
	myQueue q;
public:
	void facade()
	{
		init();
		std::cout << selection();
	}
	void init()
	{
		try
		{
			std::cin >> _n >> _k;
			for (int i = 1; i <= _n; i++)
				q.push(i);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	int selection()
	{		
		auto run = [this]() -> int
		{
			int res;
			int index(0);

			while (!q.empty())
			{
				index++;
				if (index % _k == 0)
				{
					res = q.front();
					q.pop();
				}
				else
				{
					q.push(q.front());
					q.pop();
				}
			}

			return res;
		};
		
		return run();
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}