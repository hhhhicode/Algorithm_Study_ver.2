// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try

#include <iostream>

class Problem
{
private:
	int c[8]{ 1, };
	bool ch[10];

public:
	void facade()
	{
		DFS();
	}
	void DFS(int index = 1)
	{
		if (index >= 8)
		{
			if (func1() + func2() == func3())
			{
				printRes();
				exit(0);
			}
			return;
		}
		else
		{
			for (int num = 0; num <= 9; ++num)
			{
				if (ch[num] == false)
				{
					ch[num] = true;
					c[index] = num;
					DFS(index + 1);
					ch[num] = false;
				}
			}
		}
	}
	int func1()
	{
		return c[4] * 1000 + c[3] * 100 + c[5] * 10 + c[6];
	}
	int func2()
	{
		return c[0] * 1000 + c[1] * 100 + c[2] * 10 + c[3];
	}
	int func3()
	{
		return c[0] * 10000 + c[1] * 1000 + c[5] * 100 + c[3] * 10 + c[7];
	}
	void printRes()
	{
		std::cout << func1() << " + " << func2() << " = " << func3();
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}