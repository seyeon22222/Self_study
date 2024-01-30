#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int dp[101][100001];

int main()
{
	int n,k,w,v;
	cin >> n >> k;
	int m_w = 0;
	vector<pair<int, int>> arr;
	for (int i = 0; i < n; i++)
	{
		cin >> w >> v;
		arr.push_back(make_pair(w,v));
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{ 
			int wei = arr[i - 1].first;
			int val = arr[i - 1].second;
			if (wei <= j)
				dp[i][j] = max(dp[i][j], val);
			if (wei + j <= k)
				dp[i][j + wei] = max(dp[i - 1][j + wei], dp[i - 1][j] + val);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	cout << dp[n][k];
}
