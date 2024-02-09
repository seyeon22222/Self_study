#include <iostream>
#include <vector>
using namespace std;

# define MAX 987654321

int n;
int res = MAX;
int dp[1001][3];
int color[1001][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r,g,b;
		cin >> r >> g >> b;
		color[i][0] = r;
		color[i][1] = g;
		color[i][2] = b;
	}

	for (int a = 0; a < 3; ++a)
	{
		for (int b = 0; b < 3; ++b)
		{
			if (a == b)
				dp[0][b] = color[0][b];
			else
				dp[0][b] = MAX;
		}

		for (int i = 1; i <= n; ++i)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + color[i][0];
			dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]) + color[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + color[i][2];
		}

		for (int c = 0; c < 3; ++c)
			if (a != c)
				res = min(res, dp[n - 1][c]);
	}
	
	cout << res;
}