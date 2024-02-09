#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
vector<pair<int, int>> v;
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r, c;
		cin >> r >> c;
		v.push_back(make_pair(r, c));
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i)
		dp[i][i] = 0;
	// 따로 나누어서 계산할 행렬의 갯수
	for (int k = 1; k < n; ++k)
	{
		// 시작 행렬의 인덱스
		for (int i = 0; i < n - k; ++i)
		{
			// mid인덱스
			int pos = i + k;
			// 끝 인덱스
			for (int j = i; j < pos; ++j)
			{
				if (!dp[i][pos])
					dp[i][pos] = dp[i][j] + dp[j + 1][pos] + v[i].first * v[j].second * v[pos].second;
				else
					dp[i][pos] = min(dp[i][pos], dp[i][j] + dp[j + 1][pos] + v[i].first * v[j].second * v[pos].second);
			}
		}
	}
	// for (int i = 0; i < 10; ++i)
	// {
	// 	for (int j = 0; j < 10; ++j)
	// 		cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	cout << dp[0][n - 1];
}