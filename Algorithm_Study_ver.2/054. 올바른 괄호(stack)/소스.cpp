// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// template
#include <iostream>

template<class T>
class Stack
{
private:
	T memory[30];
	int p = -1;

public:
	void setMemory(const T& value)
	{
		memory[++p] = value;
	}
	bool getMemory()
	{
		if (p-- >= 0)
			return true;
		else
		{
			return false;
		}
	}
	void printStack()
	{
		for (int i = 0; i <= p; i++)
		{
			std::cout << memory[i];
		}
		std::cout << std::endl;
	}
};

class Problem
{
private:
	Stack<char> stack;
	char str[31];

public:
	void facade()
	{
		init();
		solution();
	}
	void init()
	{
		std::cin >> str;
	}
	void solution()
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(')
			{
				stack.setMemory(str[i]);
			}
			else
			{
				if (!stack.getMemory())
				{
					std::cout << "NO";
					return;
				}
			}
		}
		if (stack.getMemory())
		{
			std::cout << "NO";
			return;
		}
		std::cout << "YES";
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}