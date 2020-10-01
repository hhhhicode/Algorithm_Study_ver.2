// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// template, auto, lambda, using, unique_ptr, try
#include <iostream>

template <typename T>
class Problem
{
	using myUnique = std::unique_ptr<T[]>;
private:
	int _n;
	myUnique list = nullptr;
	std::unique_ptr<bool[]> ch = nullptr;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		std::cin >> _n;
		ch = std::make_unique<bool[]>(_n);
		list = std::make_unique<T[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}
	void solution(const int& index = 0)
	{
		auto checkRes = [this]()
		{
			T sumTrue(0);
			T sumFalse(0);
			for (int i = 0; i < _n; i++)
				ch[i] == true ? sumTrue += list[i] : sumFalse += list[i];
			if (sumTrue == sumFalse)
			{
				std::cout << "YES";
				exit(0);
			}
			if (sumTrue == 0)
			{
				std::cout << "NO";
			}
		};

		if (index >= _n)
		{
			checkRes();
			return;
		}
		else
		{
			ch[index] = true;
			solution(index + 1);

			ch[index] = false;
			solution(index + 1);
		}
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}