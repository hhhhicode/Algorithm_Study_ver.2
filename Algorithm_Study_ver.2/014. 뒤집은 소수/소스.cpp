// template, auto, lambda, function pointer, tuple, typedef
// function pointer, auto, lambda

#include <iostream>

int reverse(int x)
{
	int rNum = 0;
	while (x != 0)
	{
		rNum = rNum * 10 + x % 10;
		x /= 10;
	}
	return rNum;
}

bool isPrime(int x)
{
	if (x == 1) return false;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	using namespace std;

	int n;
	cin >> n;
	int (*rFunc)(int) = reverse;
	bool (*pFunc)(int) = isPrime;

	auto solution = [&]() -> void
	{
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			auto rNumber = rFunc(number);
			if (pFunc(rNumber) == true) cout << rNumber << ' ';
		}
	};
	
	solution();

	return 0;
}