// 틀린 문제
// m, d 순으로 정렬시키면 m은 높지만 d가 1인 것이 맨 위에 올 수 있다.

// priority_queue는 m을 기준으로 정렬하고, push할 때 d일째 것들 입력 -> 선택 -> d-1일째 것들 입력 -> 선택 -> ...
// 이렇게 풀어야 한다.
// tuple로 하지 않고, 구조체로 하는게 operator을 오버로딩 하기 더 편한 것 같다.

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
			// d에 대해 정렬하고 거기에 맞춰서 나중에 m을 pQ에 넣음 ( 체크 부분 1번째 )
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

			// 비어있는 날짜가 있으면 안넣음 ( 체크 부분 2번째 )
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