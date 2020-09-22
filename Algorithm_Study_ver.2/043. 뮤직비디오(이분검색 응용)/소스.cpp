// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>
#include <exception>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _m;	// n개의 노래, m개의 dvd
	myUnique musics = nullptr;

public:
	void facade()
	{
		std::cout << binarySearch(init());
	}
	int init()
	{
		int sum(0);
		try
		{
			std::cin >> _n >> _m;
			musics = std::make_unique<int[]>(_n);
			for (int i = 0; i < _n; i++)
			{
				std::cin >> musics[i];
				sum += musics[i];
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		return sum;
	}

	int binarySearch(const int& sum)
	{
		auto checkMid = [this](const int& mid) -> bool
		{
			int count(1);
			for (int i = 0, tape(0); i < _n; i++)
			{
				if (tape + musics[i] <= mid)
					tape += musics[i];
				else
				{
					count++;
					tape = musics[i];
				}
				if (_m < count) // 용량이 더 커야한다.
					return false;
			}
			if (_m >= count) // 용량이 적정하거나 작아도 된다.
				return true;
			return false;
		};

		int lt = 0, rt = sum;
		int result;

		while (lt <= rt)
		{
			int mid = (lt + rt) / 2;
			if (checkMid(mid) == true)
			{
				result = mid;
				rt = mid - 1;
			}
			else
			{
				lt = mid + 1;
			}
		}
		return result;
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}