// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// template, using, unique_ptr, try
#include <iostream>

template <class T>
class Problem
{
	using myUnique = std::unique_ptr<T[]>;
	using myCheck = std::unique_ptr<bool[]>;
	using cir = const int&;
private:
	int _n, _m;
	int count{ 0 };
	myUnique list = nullptr;
	myCheck ch = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << count;
	}
	void init()
	{
		try
		{
			std::cin >> _n >> _m;
			list = std::make_unique<T[]>(_n);
			ch = std::make_unique<bool[]>(_n);
			for (int i = 0; i < _n; i++)
				std::cin >> list[i];
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(cir sum = 0, cir index = 0)
	{
		if (index >= _n)
		{
			if (sum == _m)
				count++;
			return;
		}
		else
		{
			solution(sum + list[index], index + 1);

			solution(sum - list[index], index + 1);

			solution(sum, index + 1);
		}
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}