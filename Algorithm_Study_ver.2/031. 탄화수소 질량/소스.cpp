// template, auto, lambda, function pointer, tuple, typedef, unique_ptr

#include <iostream>

class Problem
{
private:
	char str[10];
	int C;
	int H;

public:
	void facade()
	{
		init();
		run();
		std::cout << C + H;
	}
	void init()
	{
		std::cin >> str;
	}
	void run()
	{
		int pointer = 0;
		int count = 0;
		for (;; pointer++)
		{
			if ('0' <= str[pointer] && str[pointer] <= '9')
			{
				count = count * 10 + int(str[pointer] - '0');
			}
			if (str[pointer] == 'H')
			{
				if (count == 0) count = 1;
				C = count * 12;
				count = 0;
			}
			if (str[pointer] == '\0')
			{
				if (count == 0) count = 1;
				H = count;
				break;
			}
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}