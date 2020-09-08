// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// auto, lambda, unique_ptr

#include <iostream>

int main()
{	// 1 : 가위, 2 : 바위, 3 : 보
	using namespace std;

	int n;
	cin >> n;

	auto init = [&]() -> int*
	{
		int* tmp = new int[n];
		for (int i = 0; i < n; i++)
			cin >> tmp[i];
		return tmp;
	};

	auto check = [](const int& a, const int& b) -> char
	{
		if (a == b)	return 'D';
		if (a == 1 && b == 3) return 'A';
		if (a == 2 && b == 1) return 'A';
		if (a == 3 && b == 2) return 'A';
		return 'B';
	};

	auto solution = [&]() -> void
	{
		std::unique_ptr<int[]> A(init());
		std::unique_ptr<int[]> B(init());

		for (int i = 0; i < n; i++)
		{
			cout << check(A[i], B[i]) << endl;
		}
	};
	//

	solution();

	return 0;
}