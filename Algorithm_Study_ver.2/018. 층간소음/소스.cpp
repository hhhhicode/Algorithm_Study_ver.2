// template, auto, lambda, function pointer, tuple, typedef
// auto, lambda

#include <iostream>

int main()
{
	using namespace std;

	int max = 0;
	int tmp = 0;
	int n, baseline;
	cin >> n >> baseline;

	auto check = [&](const int& num) -> void
	{
		if (baseline < num)
		{
			tmp++;
			if (max < tmp) max = tmp;
		}
		else
		{
			tmp = 0;
		}
	};

	int number;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		check(number);
	}

	cout << max;

	return 0;
}