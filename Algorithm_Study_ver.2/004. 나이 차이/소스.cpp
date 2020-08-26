// template, auto, lambda, function pointer

#include <iostream>

template<typename T>
auto run(const T& N)
{
	auto result = [&]() -> int
	{
		int tmp;
		T max = 0;
		T min = 1000;
		for (T i = 0; i < N; i++)
		{
			std::cin >> tmp;
			if (max < tmp) max = tmp;
			if (min > tmp) min = tmp;
		}
		return max - min;
	};

	return result();
}

int main()
{
	using namespace std;

	int N;
	cin >> N;

	int(*funcptr)(const int&) = run;

	cout << funcptr(N);



	return 0;
}