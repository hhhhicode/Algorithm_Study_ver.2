// template, auto, lambda, function pointer, tuple, typedef
// lambda, auto

// �Ҽ��� ������ �Ǻ��Ѵ�. ���ڸ� �̷�� �� �� ���� ū ���� �ڽ��� ��Ʈ�� ���̴�.
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