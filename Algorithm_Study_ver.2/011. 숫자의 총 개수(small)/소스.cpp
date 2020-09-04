// template, auto, lambda, function pointer, tuple
// lambda
#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;

	[&]() -> void
	{
		int count = 0;
		for (int i = 1; i <= n; i++)
		{
			int tmp = i;
			while (tmp != 0)
			{
				tmp = tmp / 10;
				count++;
			}
		}
		cout << count;
	}();

	return 0;
}