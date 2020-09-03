// template, auto, lambda, function pointer, [] & tuple
// auto, lambda, tuple

#include <iostream>
#include <tuple>

class 숫자만추출
{
private:
	char clist[50];

public:
	void solution()
	{
		init();
		auto [a, b] = 숫자추출과약수구하기();
		std::cout << a << std::endl << b;
	}

	void init()
	{
		std::cin >> clist;
	}

	std::tuple<int, int> 숫자추출과약수구하기()
	{
		auto 숫자추출 = [&]() -> int{
			auto sum = 0;
			for (int i = 0; clist[i] != '\0'; i++)
			{
				auto thischar = int(clist[i] - '0');
				if (0 <= thischar && thischar <= 9)
					sum = sum * 10 + thischar;
			}
			return sum;
		};
		
		auto 약수구하기 = [&](const int& sum) -> int {
			int count = 0;
			for (int i = 1; i <= sum / 2; i++)
			{
				if (sum % i == 0)
					count++;
			}
			return count + 1;
		};

		auto 숫자 = 숫자추출();
		auto 약수개수 = 약수구하기(숫자);

		return std::tuple(숫자, 약수개수);
	}
};

int main()
{
	using namespace std;

	숫자만추출().solution();

	return 0;
}