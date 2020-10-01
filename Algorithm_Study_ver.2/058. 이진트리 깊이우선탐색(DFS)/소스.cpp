// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// unique_ptr
#include <iostream>

class Problem
{
	// 1. 이진트리 생성 부분
	// 2. 순회부분
private:
	int _n;
	std::unique_ptr<int[]> nodes = nullptr;

public:
	void facade()
	{
		init();
		전위순회(1);
		std::cout << std::endl;
		중위순회(1);
		std::cout << std::endl;
		후위순회(1);
		std::cout << std::endl;

	}
	void init()
	{
		std::cin >> _n;
		nodes = std::make_unique<int[]>(_n + 1);
		for (int i = 1; i <= _n; i++)
		{
			nodes[i] = i;
		}
	}
	void 전위순회(const int& v)
	{
		if (v > _n) return;
		std::cout << nodes[v] << ' ';
		전위순회(v * 2);
		전위순회(v * 2 + 1);
	}
	void 중위순회(const int& v)
	{
		if (v > _n) return;
		중위순회(v * 2);
		std::cout << nodes[v] << ' ';
		중위순회(v * 2 + 1);
	}
	void 후위순회(const int& v)
	{
		if (v > _n) return;
		후위순회(v * 2);
		후위순회(v * 2 + 1);
		std::cout << nodes[v] << ' ';
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}