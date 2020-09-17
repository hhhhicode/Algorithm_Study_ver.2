// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr
// auto, lambda, using, unique_ptr
#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	myUnique ch = nullptr;
	myUnique numList = nullptr;

public:
	void facade()
	{
		init();
		inversionSequence();
		printRes();
	}
	void init()
	{
		std::cin >> _n;
		numList = std::make_unique<int[]>(_n + 1);
		ch = std::make_unique<int[]>(_n + 1);
		for (int i = 1; i <= _n; i++)
			std::cin >> ch[i];
	}
	void inversionSequence()
	{
		// 숫자는 자신보다 큰것의 개수를 기준으로 매겨진다.
		// 큰 숫자부터 해야 기준이 된다.

		auto push = [this](const int& j) -> void
		{
			for (int k = _n - 1; k >= j; k--)
			{
				numList[k + 1] = numList[k];
			}
		};

		for (int i = _n; i >= 1; i--)
		{
			int count(0);
			for (int j = 1; j <= _n; j++)
			{
				if (count == ch[i])
				{
					push(j);
					numList[j] = i;
					break;
				}
				if (i < numList[j]) count++;
			}
		}
	}

	void printRes()
	{
		for (int i = 1; i <= _n; i++)
		{
			std::cout << numList[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}