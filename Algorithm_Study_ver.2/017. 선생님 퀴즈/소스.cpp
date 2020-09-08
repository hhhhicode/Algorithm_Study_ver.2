// template, auto, lambda, function pointer, tuple, typedef
// auto, lambda

#include <iostream>

int main()
{
	using namespace std;

	auto sumFunc = [](int n) -> int
	{
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			sum += i;
		}
		return sum;
	};

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;

		int m;
		cin >> m;
		if (sumFunc(n) == m) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}