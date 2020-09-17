// template, auto, lambda, function pointer, tuple, typedef || using, unique_ptr
// auto, lambda, typedef, unique_ptr

#include <iostream>

class Problem
{
	typedef std::unique_ptr<int[]> myUnique;
private:
	int _n, _m;
	myUnique arr1 = nullptr;
	myUnique arr2 = nullptr;

public:
	void facade()
	{
		init();
		Res();
	}
	void init()
	{
		// unique_ptr을 매개변수로 사용시 &를 취해주지 않으면 복사대입이 발생하여 소유권문제가 발생한다.
		auto scan = [this](int& var, myUnique& arr) -> void
		{
			std::cin >> var;
			arr = std::make_unique<int[]>(var);
			for (int i = 0; i < var; i++)
				std::cin >> arr[i];
		};

		scan(_n, arr1);
		scan(_m, arr2);
	}

	void Res()
	{
		auto afterPrint = [this](myUnique& arr, int& pointer, const int& max) -> void
		{
			while (pointer != max)
			{
				std::cout << arr[pointer++] << ' ';
			}
		};

		int pointer1(0), pointer2(0);
		while (pointer1 != _n && pointer2 != _m)
		{
			if (arr1[pointer1] < arr2[pointer2])
			{
				std::cout << arr1[pointer1++] << ' ';
			}
			else
			{
				std::cout << arr2[pointer2++] << ' ';
			}
		}

		afterPrint(arr1, pointer1, _n);
		afterPrint(arr2, pointer2, _m);
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}