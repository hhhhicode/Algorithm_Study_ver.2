// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// unique_ptr
#include <iostream>

class Problem
{
	// 1. ����Ʈ�� ���� �κ�
	// 2. ��ȸ�κ�
private:
	int _n;
	std::unique_ptr<int[]> nodes = nullptr;

public:
	void facade()
	{
		init();
		������ȸ(1);
		std::cout << std::endl;
		������ȸ(1);
		std::cout << std::endl;
		������ȸ(1);
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
	void ������ȸ(const int& v)
	{
		if (v > _n) return;
		std::cout << nodes[v] << ' ';
		������ȸ(v * 2);
		������ȸ(v * 2 + 1);
	}
	void ������ȸ(const int& v)
	{
		if (v > _n) return;
		������ȸ(v * 2);
		std::cout << nodes[v] << ' ';
		������ȸ(v * 2 + 1);
	}
	void ������ȸ(const int& v)
	{
		if (v > _n) return;
		������ȸ(v * 2);
		������ȸ(v * 2 + 1);
		std::cout << nodes[v] << ' ';
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}