// template, auto, lambda, function pointer, [] & tuple
// lambda
#include <iostream>
#include <stack>

int main()
{
	using namespace std;

	char ele[30];
	cin >> ele;

	[&]() -> void {
		stack<char> s;
		for (int i = 0; ele[i] != '\0'; i++)
		{
			if (ele[i] == '(')
			{
				s.push(ele[i]);
			}
			else
			{
				if (s.empty())
				{
					cout << "NO";
					return;
				}
				s.pop();
			}
		}
		if (s.empty())
		{
			cout << "YES";
		}
		else
		{
			cout << "NO";
		}
	}();

	return 0;
}