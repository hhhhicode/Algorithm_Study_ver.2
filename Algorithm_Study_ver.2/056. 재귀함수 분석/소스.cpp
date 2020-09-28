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
		solution(1);
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
	void solution(const int& count)
	{
		if (count > _n) return;
		std::cout << count << ' ';
		solution(count + 1);
		return;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}