// template, auto, lambda, function pointer, tuple, typedef || using, unique/shared_ptr, try
// template, using, unique_ptr, try
#include <iostream>

template<class T>
class Stack
{
	using myUnique = std::unique_ptr<T[]>;
private:
	myUnique arr = std::make_unique<T[]>(11);
	int pointer = -1;

public:
	void push(const T& n)
	{
		arr[++pointer] = n;
	}
	T get()
	{
		return arr[pointer];
	}
	int getPointer()
	{
		return pointer;
	}
	void pop()
	{
		if (pointer >= 0)
			pointer--;
	}
};

class Problem
{
private:
	int _n, _k;
	Stack<int> stack;

public:
	void facade()
	{
		init();
		solution();
		printStack();
	}
	void init()
	{
		try
		{
			std::cin >> _n >> _k;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution()
	{
		int tmp(_n);
		while (tmp != 0)
		{
			stack.push(tmp % _k);
			tmp /= _k;
		}
	}
	void printStack()
	{
		for (int i = stack.getPointer(); i >= 0; i--)
		{
			if (stack.get() <= 9)
				std::cout << stack.get();
			else
				std::cout << char('A' + stack.get() - 10);
			stack.pop();
		}
	}
};

int main()
{
	using namespace std;

	Problem().facade();

	return 0;
}