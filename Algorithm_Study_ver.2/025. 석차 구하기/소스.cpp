// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda
#include <iostream>

int main()
{
	using namespace std;

	auto init = [](int& n) -> int*
	{
		cin >> n;
		auto list = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> list[i];
		}
		return list;
	};

	auto solution = [](const int* arr, const int& n) -> void
	{
		for (int i = 0; i < n; i++)
		{
			int count = 1;
			for (int j = 0; j < n; j++)
			{
				if (arr[i] < arr[j])
				{
					count++;
				}
			}
			std::cout << count << ' ';
		}
	};

	int n;
	auto list = init(n);
	solution(list, n);

	delete[] list;

	return 0;
}