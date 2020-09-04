// template, auto, lambda, function pointer, [] & tuple
// lambda

#include <iostream>

int main()
{
	using namespace std;

	char word[100];
	cin.getline(word, 100);

	[&]() -> void {
		int index = 0;
		for (int i = 0; word[i] != '\0'; i++)
		{
			if (word[i] != ' ')
			{
				if (word[i] < 'a')
				{
					word[index++] = word[i] + 'a' - 'A';
				}
				else
				{
					word[index++] = word[i];
				}
			}
		}
		word[index] = '\0';
	}();

	cout << word << endl;



	return 0;
}