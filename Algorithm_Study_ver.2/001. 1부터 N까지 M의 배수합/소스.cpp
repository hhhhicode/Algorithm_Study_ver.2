// ≈€«√∏¥
// auto

#include <iostream>

template<typename T>
auto run(const T& N, const T& M)
{
	auto sum = 0;
	for (int i = M; i <= N; i += M)
	{
		sum += i;
	}
	return sum;
}

int main()
{
	using namespace std;

	int N, M;
	cin >> N >> M;

	cout << run(N, M);

	return 0;
}