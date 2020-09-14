// 틀린 문제
// lt, cur, rt로 나누어서 조진다.
// 어설프게 아이디어가 떠오른다. 몇 번 조져야겠다.

// template, auto, lambda, function pointer, tuple, typedef, unique_ptr


#include <iostream>

class Problem
{
private:
	int _n;

public:
	void facade()
	{
		init();
		myFunc();
	}
	void init()
	{
		std::cin >> _n;
	}

	void myFunc()
	{
		int back(1);
		int front(_n);
		int thisNumber(0);
		int count(0);
		while (front != 0)
		{
			thisNumber = (_n/back) % 10; //
			front = _n / (back * 10);
			if (thisNumber > 3)
			{
				count += (front + 1) * back;
			}
			else if (thisNumber == 3)
			{
				count += front * back + (_n % back) + 1;
			}
			else
			{
				count += front * back;
			}
			back *= 10;
		}
		std::cout << count;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}