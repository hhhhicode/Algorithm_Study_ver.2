// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// template, auto, lambda
#include <iostream>

template<typename T>
class Problem
{
private:
	int n = 0;
	T* list = nullptr;

public:
	void solution()
	{
		init();
		auto result = [&]() -> int
		{
			T maxList = 0;
			int count = 0;
			int maxCount = 0;
			for (int i = 0; i < n; i++)
			{
				if (maxList <= list[i])
				{
					count++;
					if (maxCount < count) maxCount = count;
				}
				else
				{
					count = 1;
				}
				maxList = list[i];
			}
			return maxCount;
		}();

		std::cout << result;
	}
	void init()
	{
		std::cin >> n;
		list = new T[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> list[i];
		}
	}
};

int main()
{
	using namespace std;

	Problem<int> p;
	p.solution();

	return 0;
}