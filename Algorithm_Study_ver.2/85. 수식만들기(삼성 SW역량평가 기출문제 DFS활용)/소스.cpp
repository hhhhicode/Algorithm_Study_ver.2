// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>

template<typename T>
class Problem
{
	using myNumArr = std::unique_ptr<T[]>;
private:
	int _n;
	int max = 0, min = 1000000000;
	myNumArr nums = nullptr;
	int a[4];

public:
	void facade()
	{
		init();
		solution(nums[0]);//
		std::cout << max << std::endl << min;
	}
	void init()
	{
		auto makeNumArr = [this](const auto& _n)
		{
			nums = std::make_unique<T[]>(_n);
			for (int i = 0; i < _n; i++)
				std::cin >> nums[i];
		};
		auto makeAArr = [this](const auto& _n)
		{
			for (int i = 0; i < 4; ++i)
				std::cin >> a[i];
		};

		try
		{
			std::cin >> _n;
			makeNumArr(_n);
			makeAArr(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(const T& res, const int& L = 1) // res = nums[0], L = 1
	{
		if (L == _n)
		{
			if (max < res) max = res;
			if (min > res) min = res;
			return;
		}
		if (a[0] > 0)
		{
			a[0]--;
			solution(res + nums[L], L + 1);
			a[0]++;
		}
		if (a[1] > 0)
		{
			a[1]--;
			solution(res - nums[L], L + 1);
			a[1]++;
		}
		if (a[2] > 0)
		{
			a[2]--;
			solution(res * nums[L], L + 1);
			a[2]++;
		}
		if (a[3] > 0)
		{
			a[3]--;
			solution(res / nums[L], L + 1);
			a[3]++;
		}
	}
	void printA()
	{
		for (int i = 0; i < 4; i++)
			std::cout << a[i] << ' ';
		std::cout << std::endl;
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}