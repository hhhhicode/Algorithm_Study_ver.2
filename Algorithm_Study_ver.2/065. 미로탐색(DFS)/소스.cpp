// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, using, unique_ptr, try

#include <iostream>

class Problem
{
	using myUnique = std::unique_ptr<int[]>;
	using cir = const int&;
private:
	std::unique_ptr<myUnique[]> map = nullptr;
	int _size{ 7 };
	int count{ 0 };

public:
	void facade()
	{
		init();
		solution();
		std::cout << count;
	}
	void init()
	{
		auto makeMap = [this]()
		{
			map = std::make_unique<myUnique[]>(_size + 1);
			for (int i = 1; i <= _size; i++)
				map[i] = std::make_unique<int[]>(_size + 1);
			for (int i = 1; i <= _size; i++)
				for (int j = 1; j <= _size; j++)
					std::cin >> map[i][j];
			map[1][1] = 1;	// (1, 1)에서 시작하므로 check
		};

		try
		{
			makeMap();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(cir i = 1, cir j = 1)
	{
		if (i == _size && j == _size)
		{
			count++;
			return;
		}
		else
		{
			int xl[]{ -1,0,1,0 }, yl[]{ 0,1,0,-1 };
			int thereX, thereY;
			for (int l = 0; l < 4; l++)
			{
				thereX = i + xl[l];
				thereY = j + yl[l];
				if (1 <= thereX && thereX <= _size && 1 <= thereY && thereY <= _size && map[thereX][thereY] == 0)
				{
					map[thereX][thereY] = 1;
					solution(thereX, thereY);
					map[thereX][thereY] = 0;
				}
			}
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}