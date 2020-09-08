// template, auto, lambda, function pointer, tuple, typedef
// lambda, auto
#include <iostream>

int main()
{
	using namespace std;

	int memo[100]{};

	char str1[100];
	cin >> str1;

	char str2[100];
	cin >> str2;

	auto solution = [&](char str1[], char str2[]) -> void
	{
		int ch;
		auto check = [&](char str[], int flag) -> void
		{
			for (int i = 0; str[i] != '\0'; i++)
			{
				if ('A' <= ch && ch <= 'Z')
				{
					ch = int(str[i] - 'A');
				}
				else
				{
					ch = int(str[i] - 'a');
				}
				if (flag == 1)
					memo[ch]++;
				else
					memo[ch]--;
			}
		};
		
		check(str1, 1);
		check(str2, 2);

		for (int i = 0; memo[i] != '\0'; i++)
		{
			if (memo[i] != 0)
			{
				cout << "NO";
				return;
			}
		}
		cout << "YES";
	};

	solution(str1, str2);

	return 0;
}