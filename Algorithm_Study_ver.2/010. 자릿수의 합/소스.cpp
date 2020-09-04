// template, auto, lambda, function pointer, tuple
// auto, lambda, tuple

#include <iostream>
#include <string>
#include <tuple>



int main()
{
	using namespace std;

	int n;
	string* s_numbers = nullptr;
	auto init = [&]() -> void
	{
		cin >> n;
		s_numbers = new string[n];
		for (int i = 0; i < n; i++)
		{
			cin >> s_numbers[i];
		}
	};

	auto 변환 = [&](const auto& thisString) -> tuple<int, int>
	{
		int thisNumber = 0;
		int thisSum = 0;
		for (int j = 0; thisString[j] != '\0'; j++)
		{
			thisNumber = thisNumber * 10 + int(thisString[j] - '0');
			thisSum += int(thisString[j] - '0');
		}

		return make_tuple(thisSum, thisNumber);
	};

	auto 최대찾기 = [&]() -> void
	{
		int maxSum = 0;
		int maxNumber = 0;

		for (int i = 0; i < n; i++)
		{
			auto[thisSum, thisNumber] = 변환(s_numbers[i]);
			if (maxSum < thisSum)
			{
				maxSum = thisSum;
				maxNumber = thisNumber;
			}
			else if (maxSum == thisSum)
			{
				if (maxNumber < thisNumber)	maxNumber = thisNumber;
			}
		}

		cout << maxNumber;
	};
	
	init();
	최대찾기();

	return 0;
}