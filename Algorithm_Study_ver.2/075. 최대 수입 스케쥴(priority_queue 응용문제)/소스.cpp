// Ʋ�� ����
// m, d ������ ���Ľ�Ű�� m�� ������ d�� 1�� ���� �� ���� �� �� �ִ�.

// priority_queue�� m�� �������� �����ϰ�, push�� �� d��° �͵� �Է� -> ���� -> d-1��° �͵� �Է� -> ���� -> ...
// �̷��� Ǯ��� �Ѵ�.
// tuple�� ���� �ʰ�, ����ü�� �ϴ°� operator�� �����ε� �ϱ� �� ���� �� ����.

// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

class Data
{
private:
	int _m;
	int _d;
public:
	Data(const int& m, const int& d) : _m(m), _d(d) {}
	bool operator < (const Data& t)
	{
		return _d > t._d;
	}

	int getM()
	{
		return _m;
	}
	int getD()
	{
		return _d;
	}
};

using mypQ = std::priority_queue<int>;
class Problem
{
private:
	mypQ pQ;
	std::vector<Data> arr;
	int _n;

public:
	void facade()
	{
		init();
		//printArr();
		std::cout << solution();
	}
	void init()
	{
		auto makeArr = [this]() -> void
		{
			// d�� ���� �����ϰ� �ű⿡ ���缭 ���߿� m�� pQ�� ���� ( üũ �κ� 1��° )
			for (int i = 0, m, d; i < _n; i++)
			{
				std::cin >> m >> d;
				arr.push_back(Data(m, d));
			}
		};

		try
		{
			std::cin >> _n;
			makeArr();
			std::sort(arr.begin(), arr.end());
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int solution()
	{
		int sum(0);
		int j = 0;
		for (int i = arr[0].getD(); i >= 1; i--)
		{
			for (; j < _n; j++)
			{
				if (arr[j].getD() == i)
					pQ.push(arr[j].getM());
				else break;
			}

			// ����ִ� ��¥�� ������ �ȳ��� ( üũ �κ� 2��° )
			if (!pQ.empty())
			{
				sum += pQ.top();
				pQ.pop();
			}
		}
		return sum;
	}
	void printArr()
	{
		std::cout << std::endl;
		for (int i = 0; i < _n; i++)
		{
			std::cout << arr[i].getM() << ' ' << arr[i].getD() << std::endl;
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}