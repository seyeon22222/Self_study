#include <iostream>
#include <algorithm>
using namespace std;

int mi[101];
int ci[101];
//1차원 갯수, 2차원 c
int dp[101][10001];
int total_c;
int main()
{
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> mi[i];
	for (int i = 1; i <= n; i++)
	{
		cin >> ci[i];
		total_c += ci[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= total_c; j++)
		{
			if (j - ci[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - ci[i]] + mi[i]);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= total_c; i++)
	{
		if (dp[n][i] >= m)
		{
			cout << i;
			break;
		}
	}
}