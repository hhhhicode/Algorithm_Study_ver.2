// template, auto, lambda, function pointer, [] & tuple
// auto, lambda, [] & tuple

#include <iostream>
#include <tuple>


class Calc
{
private:
	char key[15];

public:
	void init()
	{
		std::cin >> key;
	}

	void solution()
	{
		[&]() -> void {
			init();
			auto [year, sex] = 나이계산();
			std::cout << year << ' ' << sex;
		}();		
	}

	std::tuple<int, char> 년생성별결정()
	{
		switch (int(key[7] - '0'))
		{
		case 1 :
			return std::make_tuple(1900, 'M');
		case 2 :
			return std::make_tuple(1900, 'W');
		case 3 :
			return std::make_tuple(2000, 'M');
		case 4 :
			return std::make_tuple(2000, 'W');
		default :
			return std::make_tuple(0, 'e');
		}
	}

	std::tuple<int, char> 나이계산()
	{
		auto [year, sex] = 년생성별결정();
		year += int(key[0] - '0') * 10 + int(key[1] - '0');
		year = 2019 - year + 1;
		return std::make_tuple(year, sex);
	}
};

int main()
{
	using namespace std;

	Calc().solution();

	return 0;
}