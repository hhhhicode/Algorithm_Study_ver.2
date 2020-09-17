// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr
// auto, lambda, typedef, unique_ptr
#include <iostream>

class Problem
{
	typedef std::unique_ptr<int[]> myUniq;
private:
	int _S, _N; // 캐시 크기, 작업의 개수
	myUniq ch = nullptr;
	myUniq cache = nullptr;

public:
	void facade()
	{
		init();
		customSelectSort();
		printRes();
	}
	void init()
	{
		std::cin >> _S >> _N;
		ch = std::make_unique<int[]>(101);
		cache = std::make_unique<int[]>(_S);
	}
	void customSelectSort()
	{
		auto missing = [this](const int& missNum) -> void
		{
			ch[cache[_S - 1]] = 0;
			for (int i = _S - 1 - 1; i >= 0; i--)
			{
				cache[i + 1] = cache[i];
			}
			cache[0] = missNum;
			ch[missNum] = 1;
		};
		auto hitting = [this](const int& hitNum) -> void
		{
			ch[hitNum] = 1;
			for (int i = 0; i < _S; i++)
			{
				if (cache[i] == hitNum)
				{
					int j = i - 1;
					for (; 0 <= j; j--)
					{
						cache[j + 1] = cache[j];
					}
					cache[j + 1] = hitNum;
				}
			}
		};

		int task;
		for (int i = 0; i < _N; i++)
		{
			std::cin >> task;
			if (ch[task] == 0)
			{
				missing(task);
			}
			else
			{
				hitting(task);
			}
		}
	}

	void printRes()
	{
		for (int i = 0; i < _S; i++)
		{
			std::cout << cache[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}