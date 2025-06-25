#include <iostream>
#include <algorithm>
using namespace std;

double cnt_a, cnt_b;
double dp[19][19][19];


bool prime_check(int score) {
	if (score == 0 || score == 1)
		return false;
	for (int i = 2; i < score; ++i) {
		if (score % i == 0)
			return false;
	}
	return true;
}

double solve(int turn, int x, int y) {
	if (turn > 17) {
		if (prime_check(x))
			return 1;
		if (prime_check(y))
			return 1;
		return 0;
	}
	if (dp[turn][x][y])
		return dp[turn][x][y];
	dp[turn][x][y] += solve(turn + 1, x, y) * (1 - cnt_a) * (1 - cnt_b);
	dp[turn][x][y] += solve(turn + 1, x + 1, y) * cnt_a * (1 - cnt_b);
	dp[turn][x][y] += solve(turn + 1, x, y + 1) * (1 - cnt_a) * cnt_b;
	dp[turn][x][y] += solve(turn + 1, x + 1, y + 1) * cnt_a * cnt_b;

	return dp[turn][x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> cnt_a >> cnt_b;
	cnt_a /= 100;
	cnt_b /= 100;
	cout << solve(0, 0, 0);
}