// template, auto, lambda

#include <iostream>

template<typename T>
auto run(const T& n)
{
	T sum = 1;

	std::cout << 1;
	for (T i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			std::cout << " + " << i;
			sum += i;
		}
	}
	std::cout << " = ";

	return sum;
}

int main()
{
	using namespace std;
	
	int N;
	cin >> N;

	//[&] () -> auto{ cout << run(N); }();
	[] (const int& n) -> auto{ cout << run(n); }(N);

	return 0;
}