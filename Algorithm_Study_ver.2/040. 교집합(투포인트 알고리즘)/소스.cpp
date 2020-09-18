// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr
// template, auto, lambda, using, unique_ptr
#include <iostream>

template <typename T>
class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n, _m;
	myUnique arr1 = nullptr;
	myUnique arr2 = nullptr;

public:
	void facade()
	{
		init();
		arrSort();
		compareArr();
	}
	void init()
	{
		auto scan = [this](int& size, myUnique& arr) -> void
		{
			std::cin >> size;
			arr = std::make_unique<T[]>(size);
			for (int i = 0; i < size; i++)
				std::cin >> arr[i];
		};

		scan(_n, arr1);
		scan(_m, arr2);
	}

	void arrSort()
	{
		auto sort = [this](const int& size, myUnique& arr) -> void
		{
			for (int i = 1; i < size; i++)
			{
				T tmp(arr[i]);
				int j = i - 1;
				for (; j >= 0; j--)
				{
					if (tmp < arr[j])
					{
						arr[j + 1] = arr[j];
					}
					else break;
				}
				arr[j + 1] = tmp;
			}
		};

		sort(_n, arr1);
		sort(_m, arr2);
	}

	void compareArr()
	{
		[this]() -> void
		{
			int pointer1 = 0, pointer2 = 0;
			while (pointer1 != _n && pointer2 != _m)
			{
				if (arr1[pointer1] == arr2[pointer2])
				{
					print(arr1[pointer1]);
					pointer1++;
					pointer2++;
				}
				else if (arr1[pointer1] < arr2[pointer2])
				{
					pointer1++;
				}
				else
				{
					pointer2++;
				}
			}
		}();
	}
	void print(const T& v)
	{
		std::cout << v << ' ';
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}