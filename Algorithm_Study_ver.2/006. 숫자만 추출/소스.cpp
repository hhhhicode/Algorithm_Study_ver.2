// template, auto, lambda, function pointer, [] & tuple
// auto, lambda, tuple

#include <iostream>
#include <tuple>

class ���ڸ�����
{
private:
	char clist[50];

public:
	void solution()
	{
		init();
		auto [a, b] = ���������������ϱ�();
		std::cout << a << std::endl << b;
	}

	void init()
	{
		std::cin >> clist;
	}

	std::tuple<int, int> ���������������ϱ�()
	{
		auto �������� = [&]() -> int{
			auto sum = 0;
			for (int i = 0; clist[i] != '\0'; i++)
			{
				auto thischar = int(clist[i] - '0');
				if (0 <= thischar && thischar <= 9)
					sum = sum * 10 + thischar;
			}
			return sum;
		};
		
		auto ������ϱ� = [&](const int& sum) -> int {
			int count = 0;
			for (int i = 1; i <= sum / 2; i++)
			{
				if (sum % i == 0)
					count++;
			}
			return count + 1;
		};

		auto ���� = ��������();
		auto ������� = ������ϱ�(����);

		return std::tuple(����, �������);
	}
};

int main()
{
	using namespace std;

	���ڸ�����().solution();

	return 0;
}