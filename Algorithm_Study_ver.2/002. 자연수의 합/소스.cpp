// template, auto, lambda

#include <iostream>

template<typename T>
auto AToBSum(const T& a, const T& b)
{
	T sum = 0;
	for (T i = a; i < b; i++)
	{
		std::cout << i << " + ";
		sum += i;
	}
	std::cout << b << " = ";
	sum += b;

	return sum;
}

int main()
{
	using namespace std;

	int A, B;
	cin >> A >> B;

	[&] () -> void { cout << AToBSum(A, B); }();

	return 0;
}