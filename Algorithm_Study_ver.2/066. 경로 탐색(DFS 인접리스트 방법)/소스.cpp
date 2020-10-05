// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try, vector
// auto, lambda, using, unique_ptr, try, vector

#include <iostream>
#include <vector>

class Problem
{
	using cir = const int&;
private:
	int _n, _m;
	int count{ 0 };
	std::vector<int>* adjList = nullptr; // vector는 list에 사용.
	bool* ch = nullptr;

public:
	~Problem()
	{
		delete ch;
	}
	void facade()
	{
		init();
		solution();
		std::cout << count;
	}
	void init()
	{
		auto makeAdjList = [this]()
		{			
			adjList = new std::vector<int>[_n + 1];
			for (int i = 0, v1, v2; i < _m; i++)
			{
				std::cin >> v1 >> v2;
				adjList[v1].push_back(v2);
			}
		};
		auto makeCheckList = [this]()
		{
			ch = new bool[_n + 1](); // ()를 적어주어 초기화 해주지 않으면 쓰레기 값이 들어간다. <-★★★★★
			ch[1] = true;
		};

		try
		{
			std::cin >> _n >> _m;
			makeAdjList();
			makeCheckList();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	void solution(cir n = 1)
	{
		if (n == _n)
		{
			count++;
			return;
		}
		else
		{
			for (auto there : adjList[n])
			{
				if (ch[there] == false)
				{
					ch[there] = true;
					solution(there);
					ch[there] = false;
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