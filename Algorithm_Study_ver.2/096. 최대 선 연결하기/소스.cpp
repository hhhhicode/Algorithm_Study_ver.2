// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda(auto), using, unique_ptr, try

// ��������. ���� ��ġ�� �ʾƾ��Ѵ�. -> ������������ ���õǾ�� �Ѵ�.
// �ΰ����� ������ �ǹ̸� �˾������� �Ѵ�.
#include <iostream>

using cir = const int&;
using myUniqueIntArr = std::unique_ptr<int[]>;

class Problem
{
private:
	int _n;
	int _res;
	myUniqueIntArr nums = nullptr;
	myUniqueIntArr length = nullptr;

public:
	void facade()
	{
		init();
		sol();
		std::cout << _res;
	}
	void init()
	{
		auto makeNums = [this](const auto& n)
		{
			nums = std::make_unique<int[]>(n);
			for (int i = 0; i < n; i++)
				std::cin >> nums[i];
		};
		auto makeLength = [this](const auto& n)
		{
			length = std::make_unique<int[]>(n);
			for (int i = 0; i < n; i++)
				length[i] = 1;
		};

		try
		{
			std::cin >> _n;
			makeNums(_n);
			makeLength(_n);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		auto searchMaxLength = [this](const auto& n) -> int
		{
			int max = 0;
			for (int i = 0; i < n; i++)
				max = max < length[i] ? length[i] : max;
			return max;
		};

		for (int i = 0; i < _n; i++)
			for (int j = 0; j < i; j++)
				if (nums[j] < nums[i])
					length[i] = length[i] < length[j] + 1 ? length[j] + 1 : length[i];
		
		_res = searchMaxLength(_n);
	}
};

int main()
{
	Problem().facade();

	return 0;
}