// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// try
#include <iostream>

class Problem
{
private:
	int _n;

public:
	void facade()
	{
		init();
		solution(_n);
	}
	void init()
	{
		try
		{
			std::cin >> _n;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(const int& v)
	{
		if (v == 0)
			return;
		solution(v / 2);
		std::cout << v % 2;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}