// template, auto, lambda, function pointer, tuple
// 
// ���� ������ Ǫ�� ����� �ִ�.
// 1~9	: 9��, 10~99	: 90��, 100~999	: 900��

#include <iostream>

class Problem {
private:
	int _n;

public:
	void solution() {
		init();
		std::cout << counter();
	}
	void init() {
		std::cin >> _n;
	}

	int counter() {
		int sum = 0;
		int d = 9;
		int c = 1;
		int res = 0;

		while (d + sum < _n) {
			sum += d;
			res += d * c;
			c++;
			d *= 10;
		}
		int tmp = _n - sum;
		res += tmp * c;

		return res;
	}
};

int main() {
	using namespace std;

	Problem().solution();

	return 0;
}