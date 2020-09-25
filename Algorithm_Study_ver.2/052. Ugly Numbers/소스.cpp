// 틀린문제

// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try

#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	myUnique list;

public:
	void facade()
	{
		init();
		solutioin();
	}
	void init()
	{
		std::cin >> _n;
		list = std::make_unique<int[]>(_n + 1);
	}
	void solutioin()
	{
		auto mulNums = [this](const int pointers[]) -> std::tuple<int, int, int>
		{
			return std::make_tuple(list[pointers[0]] * 2, list[pointers[1]] * 3, list[pointers[2]] * 5);
		};

		int count(1);	list[count] = 1;
		int pointers[3]{ 1,1,1 }; // 2, 3, 5의 곱으로 이루어진 수를 가리켜나갈것이다.
		int min;

		while (count != _n)
		{
			using cir = const int&;
			auto findMin = [this](cir num2, cir num3, cir num5) -> int
			{
				if (num2 < num3) return num2 < num5 ? num2 : num5;
				else return num3 < num5 ? num3 : num5;
			};

			auto [num2, num3, num5] = mulNums(pointers);
			int tmp[3]{ num2, num3, num5 };
			min = findMin(num2, num3, num5);
			list[++count] = min;
			for (int i = 0; i < 3; i++)
			{
				if (min == tmp[i]) pointers[i]++;
			}
		}
		std::cout << list[_n];
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}