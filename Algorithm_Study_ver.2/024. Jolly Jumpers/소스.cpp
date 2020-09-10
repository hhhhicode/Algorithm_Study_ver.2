// template, auto, lambda, function pointer, tuple, typedef, unique_ptr
// unique_ptr
#include <iostream>


class Problem
{
private:
	int _n;
	std::unique_ptr<int[]> _ch;

public:
	void solution()
	{
		init();
		check();
	}
	void init()
	{
		std::cin >> _n;
		_ch = std::make_unique<int[]>(_n);
	}
	void check()
	{
		int prev, next, minus;
		std::cin >> next;
		for (int i = 1; i < _n; i++)
		{
			prev = next;
			std::cin >> next;
			minus = std::abs(prev - next);
			if (_ch[minus] == 0 && 1 <= minus && minus < _n)
			{
				_ch[minus] = 1;
			}
			else
			{
				std::cout << "NO";
				return;
			}
		}
		std::cout << "YES";
	}
};

int main()
{
	using namespace std;

	Problem().solution();

	return 0;
}