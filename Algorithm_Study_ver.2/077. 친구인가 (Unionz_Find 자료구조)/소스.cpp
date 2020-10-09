// 틀린문제 Union에 대해 알자.

// template, auto, lambda, function pointer, pair||tuple, typedef||using, unique/shared_ptr, try


#include <iostream>

class Problem
{
	using cir = const int&;
	using myStu = std::unique_ptr<int[]>;
private:
	int _n, _m;
	myStu stu = nullptr;

public:
	void facade()
	{
		init();
		isFriend();
	}
	void init()
	{
		auto makeStu = [this](cir n, cir m) -> void
		{
			stu = std::make_unique<int[]>(_n + 1);
			for (int i = 1; i <= _n; i++)
				stu[i] = i;
			for (int i = 0, s1, s2; i < _m; i++)
			{
				std::cin >> s1 >> s2;
				Union(s1, s2);
			}
		};

		try
		{
			std::cin >> _n >> _m;
			makeStu(_n, _m);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}
	int Find(cir v)
	{
		if (stu[v] == v) return v;
		return stu[v] = Find(stu[v]);
	}
	// Union을 잘 모르겠네....
	// (1, 2) (2, 3)일때는 맞는데 (1, 2) (1, 3)일때는...?
	void Union(cir s1, cir s2)
	{
		int t1 = Find(s1);
		int t2 = Find(s2);

		if (t1 != t2) stu[t1] = t2;
	}
	void isFriend()
	{
		int A, B;
		try
		{
			std::cin >> A >> B;
			if (Find(A) == Find(B))
				std::cout << "YES";
			else std::cout << "NO";
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

	Problem().facade();

	return 0;
}