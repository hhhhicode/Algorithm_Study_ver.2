// template, auto, lambda, function pointer, tuple, typedef, unique_ptr

#include <iostream>

class Problem
{
private:
	int n, k;
	int* numList = nullptr;

public:
	void solution()
	{
		init();
		std::cout << searchMax();
	}

	void init()
	{
		std::cin >> n >> k;

		numList = new int[n];
		for (int i = 0; i < n; i++)
		{
			std::cin >> numList[i];
		}
	}

	int searchMax()
	{
		int max = 0;
		int sum;
		for (int i = 0; i < k; i++)
		{
			max += numList[i];
		}
		sum = max;

		for (int i = 0; i + k < n; i++)
		{
			sum -= numList[i];
			sum += numList[i + k];
			max = max < sum ? sum : max;
		}
		return max;
	}
};

int main()
{
	using namespace std;

	Problem().solution();


	return 0;
}