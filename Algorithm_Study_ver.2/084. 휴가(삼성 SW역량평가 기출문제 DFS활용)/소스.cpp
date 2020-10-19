// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try
// auto, lambda(auto), tuple, using, unique_ptr(*), try

#include <iostream>
#include <tuple>

class Task
{
private:
	int _Ti, _Pi;

public:
	Task() {};
	Task(int t, int p)
		: _Ti(t), _Pi(p)
	{}

	std::tuple<int, int> getTuple()
	{
		return std::tuple<int, int>(_Ti, _Pi);
	}
};

class Problem
{
	using myTaskArr = std::unique_ptr<Task*[]>;
private:
	int _N;
	int maxSum{ 0 };
	myTaskArr tasks = nullptr;

public:
	void facade()
	{
		init();
		solution();
		std::cout << maxSum;
	}
	void init()
	{
		// lambda¿¡ auto ¾²±â
		auto makeTasks = [this](const auto& n) -> void
		{
			tasks = std::make_unique<Task*[]>(n + 1);
			for (int i = 1, t, p; i <= n; i++)
			{
				std::cin >> t >> p;
				tasks[i] = new Task(t, p);
			}				
		};

		try
		{
			std::cin >> _N;
			makeTasks(_N);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void solution(int day = 1, int sum = 0)
	{
		if (day > _N)
		{
			maxSum = maxSum < sum ? sum : maxSum;
			return;
		}
		else
		{
			int d = day;
			bool dayCh = false;			

			for (; d <= _N; ++d)
			{
				auto [Ti, Pi] = tasks[d]->getTuple();
				dayCh = d + Ti <= _N + 1 ? true : false;
				if (dayCh == true)
					solution(d + Ti, sum + Pi);
				else solution(d + Ti, sum);
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