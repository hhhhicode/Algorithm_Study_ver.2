// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// auto, lambda, try
#include <iostream>

class Stack
{
private:
	int mem[30];
	char res[60];
	int p{ -1 };
	int res_p{ -1 };

public:
	void push(const int& v)
	{
		res[++res_p] = 'P';
		mem[++p] = v;
	}
	int out()
	{
		res[++res_p] = 'O';
		return mem[p--];
	}
	int peek()
	{
		if (p == -1) return 0;
		return mem[p];
	}
	void printRes()
	{
		for (int i = 0; i <= res_p; i++)
		{
			std::cout << res[i];
		}
	}
};

class Problem
{
private:
	int _n;
	Stack stack;

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		try 
		{
			std::cin >> _n;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution()
	{
		auto push = [this]() -> void
		{
			int tmp;
			std::cin >> tmp;
			stack.push(tmp);
		};
		auto out = [this](int& count) ->void
		{
			while (count == stack.peek())
			{
				stack.out();
				count++;
			}
		};
		auto checkEnd = [this]() -> bool
		{
			if (stack.peek() == 0)
				return true;
			return false;
		};

		int count{ 1 };
		for (int i = 0; i < _n; i++)
		{
			push();
			out(count);
		}
		if (checkEnd() == false)
			std::cout << "impossible";
		else
			stack.printRes();
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}