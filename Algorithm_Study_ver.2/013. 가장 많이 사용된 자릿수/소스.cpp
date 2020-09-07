// template, auto, lambda, function pointer, tuple, typedef
// function pointer, tuple, typedef

#include <iostream>
#include <tuple>

typedef std::tuple<int, int> myTuple;
myTuple tupleCompare(const myTuple& a, const myTuple& b)
{
	if (std::get<0>(a) < std::get<0>(b))
	{
		return b;
	}
	else if (std::get<0>(a) == std::get<0>(b))
	{
		if (std::get<1>(a) < std::get<1>(b))
		{
			return b;
		}
	}
	return a;
}

int main()
{
	using namespace std;

	char numbers[101];
	int check[101]{};
	cin >> numbers;

	int number = 0;
	tuple<int, int> max(0, 0); // 개수, 숫자
	myTuple(*fnc_ptr)(const myTuple&, const myTuple&) = tupleCompare;
	for (int i = 0; numbers[i] != '\0'; i++)
	{
		number = int(numbers[i] - '0');
		check[number]++;
		max = fnc_ptr(max, tuple(check[number], int(numbers[i] - '0')));
	}

	cout << get<1>(max);

	return 0;
}