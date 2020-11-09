// template, auto, lambda(auto), function pointer, pair||tuple, typedef||using, unique/shared_ptr(*), try

#include <iostream>

using cir = const int&;

class Question
{
private:
	friend class Problem;
	int _score, _time;
	
public:
	Question() {}
	Question(cir s, cir t)
		:_score(s), _time(t)
	{}
};

class Problem
{
private:
	int _n, _m; // 문제 개수(n), 제한 시간(m)
	std::unique_ptr<Question[]> quest = nullptr;
	std::unique_ptr<int[]> score = nullptr;
public:
	void facade()
	{
		init();
		sol();
		std::cout << score[_m];
	}
	void init()
	{
		auto makeQuestionAndScoreArr = [this](cir n, cir m) -> void
		{
			quest = std::make_unique<Question[]>(n);
			score = std::make_unique<int[]>(m + 1);
			for (int i = 0, s, t; i < n; i++)
			{
				std::cin >> s >> t;
				quest[i] = Question(s, t);
			}
		};
		try
		{
			std::cin >> _n >> _m;
			makeQuestionAndScoreArr(_n, _m);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	void sol()
	{
		for (int i = 0; i < _n; i++)
		{
			auto& qTime = quest[i]._time;
			auto& qScore = quest[i]._score;
			for (int j = _m; j >= qTime; j--)
				score[j] = score[j] < score[j - qTime] + qScore ? score[j - qTime] + qScore : score[j];
		}
	}
};

int main()
{
	Problem().facade();

	return 0;
}