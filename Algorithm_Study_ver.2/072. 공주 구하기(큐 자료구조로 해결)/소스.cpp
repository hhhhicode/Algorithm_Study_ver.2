// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, try
#include <iostream>
#include <queue>

class Problem
{
	using myQ = std::queue<int>;
private:
	int _n, _k;	// n : ¿ÕÀÚÀÇ ¼ö, k : k¹øÂ°´Â Å»¶ô
	myQ q;

public:
	void facade()
	{
		init();
		std::cout << solution();
	}
	void init()
	{
		auto inputData = [this]() -> void
		{
			for (int i = 1; i <= _n; i++)
				q.push(i);
		};

		try
		{
			std::cin >> _n >> _k;
			inputData();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int solution()
	{
		auto killPrince = [this]() -> int
		{
			int res;
			for (int i = 1; i < _k; i++)
			{
				q.push(q.front());
				q.pop();
			}
			res = q.front();
			q.pop();
			return res;
		};

		int res;
		while (!q.empty())
		{
			res = killPrince();
		}
		return res;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}