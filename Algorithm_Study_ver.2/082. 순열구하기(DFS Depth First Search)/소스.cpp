// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>

using myArr = std::unique_ptr<int[]>;
using myCheck = std::unique_ptr<bool[]>;
using cir = const int&;

class Problem
{
private:
	int _n, _r; // _n개중에 _r개 뽑기
	int count = 0;
	myArr _nums = nullptr;
	myArr _printArr = nullptr;
	myCheck _ch = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << count;
	}
	void init()
	{
		auto makeNums = [this](cir _n) -> void
		{
			_nums = std::make_unique<int[]>(_n);
			for (int i = 0; i < _n; i++)
				std::cin >> _nums[i];
		};

		try
		{
			std::cin >> _n >> _r;
			makeNums(_n);
			_printArr = std::make_unique<int[]>(_r);
			_ch = std::make_unique<bool[]>(_n);
		}
		catch (...)
		{
			std::cerr << "error";
		}
	}
	void solution(cir R = 0)
	{
		static auto printRes = [this]() -> void
		{
			for (int i = 0; i < _r; i++)
				std::cout << _printArr[i] << ' ';
			std::cout << std::endl;
		};

		if (R >= _r)
		{
			printRes();
			count++;
			return;
		}
		else
		{
			for (int i = 0; i < _n; i++)
			{
				if (_ch[i] == false)
				{
					_ch[i] = true;
					_printArr[R] = _nums[i];
					solution(R + 1);
					_ch[i] = false;
				}
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