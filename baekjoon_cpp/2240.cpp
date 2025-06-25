#include <iostream>
using namespace std;

int t, w;
int _time[1001];
int dp[1001][31][3];

int solve(int _t, int m, int flag) {
	if (m == w || _t > t)
		return 0;

	if (dp[_t][m][flag])
		return dp[_t][m][flag];
	

	if (flag == 1)
		dp[_t][m][1] += max(solve(_t + 1, m + 1, 2), solve(_t + 1, m, 1));
	if (flag == 2)
		dp[_t][m][2] += max(solve(_t + 1, m, 2), solve(_t + 1, m + 1, 1));
	if (_time[_t] == flag) {
		dp[_t][m][flag]++;
	}

	return max(dp[t][m][1], dp[t][m][2]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> t >> w;

	for (int i = 1; i <= t; ++i) {
		cin >> _time[i];
	}


	max(solve(1, 0, 1), solve(1, 1, 2));

	cout << "\ndp 1\n";
	for (int i = 1; i <= t; ++i) {
		for (int j = 0; j <= w; ++j) {
			cout << dp[i][j][1] << " ";
		}
		cout << "\n";
	}

	cout << "\ndp 2\n";
	for (int i = 1; i <= t; ++i) {
		for (int j = 0; j <= w; ++j) {
			cout << dp[i][j][2] << " ";
		}
		cout << "\n";
	}

}