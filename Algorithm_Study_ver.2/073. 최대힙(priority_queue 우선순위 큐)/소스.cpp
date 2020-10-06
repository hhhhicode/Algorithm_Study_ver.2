// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try
// try, priority_queue, 최대힙을 알자.

#include <iostream>
#include <queue>

class Problem
{
private:
	std::priority_queue<int> pQ;
public:
	void solution()
	{
		int input{ 0 };
		try
		{
			while (true)
			{
				std::cin >> input;
				if (input == -1)	return;
				if (input == 0)
				{
					if (!pQ.empty())
					{
						std::cout << pQ.top() << std::endl;
						pQ.pop();
					}
					else
						std::cout << -1 << std::endl;
				}
				else
					pQ.push(input);
			}
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
};

int main()
{
	using namespace std;

	Problem().solution();

	return 0;
}