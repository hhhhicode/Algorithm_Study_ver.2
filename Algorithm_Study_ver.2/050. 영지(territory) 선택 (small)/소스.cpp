// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _h, _w;	//_h : 세로 길이, _w : 가로 길이
	int _ah, _aw; // _ah : 영지 세로 길이, _aw : 영지 가로 길이
	std::unique_ptr<myUnique[]> arr = nullptr;
	std::unique_ptr<myUnique[]> sumArr = nullptr;

public:
	void facade()
	{
		init();
		std::cout << solution();
	}
	void init()
	{
		try
		{
			std::cin >> _h >> _w;
			arr = std::make_unique<myUnique[]>(_h + 1);
			sumArr = std::make_unique<myUnique[]>(_h + 1);
			for (int i = 0; i <= _h; i++)
			{
				arr[i] = std::make_unique<int[]>(_w + 1);
				sumArr[i] = std::make_unique<int[]>(_w + 1);
			}
			for (int i = 1; i <= _h; i++)
			{
				for (int j = 1; j <= _w; j++)
				{
					std::cin >> arr[i][j];
				}
			}
			std::cin >> _ah >> _aw;
		}
		catch(std::exception & e)
		{
			std::cerr << e.what();
		}
	}
	int solution()
	{
		auto Sum = [this](const int& iy, const int& jx) -> int
		{
			return sumArr[iy - 1][jx] + sumArr[iy][jx - 1] + arr[iy][jx];
		};

		auto areaSum = [this](const int& iy, const int& jx) -> int
		{
			return sumArr[iy][jx] - sumArr[iy - _ah][jx] - sumArr[iy][jx - _aw] + sumArr[iy - _ah][jx - _aw];
		};

		for (int i = 1; i <= _h; i++)
		{
			for (int j = 1; j <= _w; j++)
			{
				sumArr[i][j] = Sum(i, j);
			}
		}

		int max(0);
		for (int i = _ah; i <= _h; i++)
			for (int j = _aw; j <= _w; j++)
			{
				int tmp(areaSum(i, j));
				max = max < tmp ? tmp : max;
			}

		return max;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}