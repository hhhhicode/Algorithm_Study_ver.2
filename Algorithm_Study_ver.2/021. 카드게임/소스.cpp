// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// template, auto, lambda, tuple, typedef
#include <iostream>
#include <tuple>

template<typename T>
class Problem
{
private:
	T A[10];
	T B[10];
	char winner = 'D';

public:
	void solution()
	{
		init();
		std::cout << whoWinner(check(A, B));
	}

	void init()
	{
		auto read = [](T arr[]) -> void
		{
			for (int i = 0; i < 10; i++)
			{
				std::cin >> arr[i];
			}
		};

		read(A);
		read(B);		
	}
	using myTuple = std::tuple<int, int>;
	myTuple check(T arr1[], T arr2[])
	{
		int aPoint = 0, bPoint = 0;
		for (int i = 0; i < 10; i++)
		{
			if (arr1[i] == arr2[i])
			{
				aPoint++;	bPoint++;
			}
			else if (arr1[i] > arr2[i])
			{
				winner = 'A';
				aPoint += 3;
			}
			else
			{
				winner = 'B';
				bPoint += 3;
			}
		}
		std::cout << aPoint << ' ' << bPoint << std::endl;
		return std::make_tuple(aPoint, bPoint);
	}

	char whoWinner(const myTuple& t)
	{
		auto [a, b] = t;
		if (a > b)
		{
			winner = 'A';
		}
		if (a < b)
		{
			winner = 'B';
		}
		return winner;
	}
};

int main()
{
	using namespace std;

	Problem<int>().solution();

	return 0;
}