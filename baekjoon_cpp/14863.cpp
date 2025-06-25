#include <iostream>
#include <climits>
#include <ctype.h>
using namespace std;

int N, K;
pair<int, int> walk[101];
pair<int, int> bike[101];
long long dp[101][100001];

// 구간, 시간 -> 값
long long solve(int idx, int time) {
	if (idx == N + 1)
		return 0;
	if (dp[idx][time])
		return dp[idx][time];
	dp[idx][time] = -987654321;
	if (time - walk[idx].first >= 0)
		dp[idx][time] = max(dp[idx][time], solve(idx + 1, time - walk[idx].first) + walk[idx].second);
	if (time - bike[idx].first >= 0)
		dp[idx][time] = max(dp[idx][time], solve(idx + 1, time - bike[idx].first) + bike[idx].second);
	
	return dp[idx][time];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; ++i) {
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		walk[i] = {x, y};
		bike[i] = {xx, yy};
	}
	cout << solve(1, K);
}