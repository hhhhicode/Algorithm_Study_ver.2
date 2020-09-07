// template, auto, lambda, function pointer, tuple
// 
// 쉽고 빠르게 푸는 방법이 있다.
// 1~9	: 9개, 10~99	: 90개, 100~999	: 900개

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