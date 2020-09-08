// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// unique_ptr, auto

#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;
	//std::unique_ptr<int[]> uq2(new int[n]);
	auto uq = std::make_unique<int[]>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> uq[i];
	}

	int count = 0;
	int max = uq[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (max < uq[i])
		{
			count++;
			max = uq[i];
		}
	}

	cout << count;

	return 0;
}