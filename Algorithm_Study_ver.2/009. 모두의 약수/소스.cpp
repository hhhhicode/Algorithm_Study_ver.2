// template, auto, lambda, function pointer, [] & tuple
// lambda

#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;

	int memo[50001]{};
	[&](int num) -> void
	{
		for (int i = 1; i <= num; i++)
		{
			for (int j = i; j <= num; j = j + i)
			{
				memo[j]++;
			}
		}
	}(n);

	
	for (int i = 1; i <= n; i++)
	{
		cout << memo[i] << ' ';
	}

	return 0;
}