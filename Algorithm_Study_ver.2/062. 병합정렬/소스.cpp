// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// template, auto, lambda, using, unique_ptr, try
#include <iostream>

template <class T>
class Problem
{
	using myNums = std::unique_ptr<T[]>;
private:
	int _n;
	myNums nums = nullptr;
	myNums tmp = nullptr;

public:
	void facade()
	{
		init();
		mergeSort(0, _n - 1);
		printNums();
	}

	void init()
	{
		try
		{
			std::cin >> _n;
			nums = std::make_unique<T[]>(_n);
			tmp = std::make_unique<T[]>(_n);
			for (int i = 0; i < _n; i++)
				std::cin >> nums[i];
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void mergeSort(int lt, int rt)
	{
		auto sort = [&](int& pL, int& pR, int& pT, int& mid)
		{
			while (pL <= mid && pR <= rt)
				tmp[pT++] = nums[pL] < nums[pR] ? nums[pL++] : nums[pR++];

			while (pL <= mid)
				tmp[pT++] = nums[pL++];
			while (pR <= rt)
				tmp[pT++] = nums[pR++];

			for (int i = lt; i <= rt; i++)
				nums[i] = tmp[i];
		};

		if (lt >= rt)	return;
		else
		{
			int mid = (lt + rt) / 2;

			mergeSort(lt, mid);
			mergeSort(mid + 1, rt);
			
			int pL = lt, pR = mid + 1, pT = lt;
			sort(pL, pR, pT, mid);			
		}
	}

	void printNums()
	{
		for (int i = 0; i < _n; i++)
		{
			std::cout << nums[i] << ' ';
		}
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}