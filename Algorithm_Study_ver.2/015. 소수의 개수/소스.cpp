// template, auto, lambda, function pointer, tuple, typedef
// lambda, auto

// 소수는 곱으로 판별한다. 숫자를 이루는 곱 중 가장 큰 곱은 자신을 루트한 것이다.
#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;

	auto isPrime = [&](int i) -> bool
	{
		for (int j = 2; j * j <= i; j++)
		{
			if (i % j == 0) return false;
		}
		return true;
	};

	auto numbersCheck = [&](int n) -> int
	{
		int count = 0;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i) == true) count++;
		}
		return count;
	};


	cout << numbersCheck(n);

	return 0;
}