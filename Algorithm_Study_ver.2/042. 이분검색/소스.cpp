// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr
// template, using, unique_ptr
#include <iostream>

template<typename T>
class Problem
{
	using myUnique = std::unique_ptr<int[]>;
private:
	int _n;
	T _m;
	myUnique list = nullptr;

public:
	void facade()
	{
		init();
		sortList(list);
		//printList();
		binarySearch(list, _m);
	}
	void init()
	{
		std::cin >> _n >> _m;
		list = std::make_unique<T[]>(_n);
		for (int i = 0; i < _n; i++)
			std::cin >> list[i];
	}

	void sortList(myUnique& list)
	{
		for (int i = 1; i < _n; i++)
		{
			T listI(list[i]);
			int j = i - 1;
			for (; j >= 0; j--)
			{
				if (listI < list[j])
					list[j + 1] = list[j];
				else break;
			}
			list[j + 1] = listI;
		}
	}

	void binarySearch(myUnique& list, const T& _m)
	{
		int lt = 0, rt = _n;		

		while (lt < rt)
		{
			int mid = (lt + rt) / 2;
			if (list[mid] == _m)
			{
				std::cout << mid + 1;
				break;
			}
			else if (list[mid] < _m)
			{
				lt = mid + 1;
			}
			else
			{
				rt = mid - 1;
			}
		}
	}

	void printList()
	{
		for (int i = 0; i < _n; i++)
			std::cout << list[i] << ' ';
	}
};

int main()
{
	using namespace std;

	Problem<int>().facade();

	return 0;
}