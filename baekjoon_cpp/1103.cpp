#include <iostream>
#include <algorithm>
using namespace std;

int r, c;
int map[51][51];
int dp[51][51];
int visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solve(int x, int y) {
	if (x > r || x <= 0 || y <= 0 || y > c || map[x][y] == 0)
		return 0;
	
	if (visited[x][y]) {
		cout << "-1";
		exit (0);
	}

	if (dp[x][y] != 0) {
		return dp[x][y];
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + (dx[i] * map[x][y]);
		int ny = y + (dy[i] * map[x][y]);
		
		dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
	}
	visited[x][y] = false;
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> r >> c;
	for (int i = 1; i <= r; ++i) {
		string str;
		cin >> str;
		int idx = 0;
		for (int j = 1; j <= c; ++j, ++idx) {
			if (str[idx] == 'H')
				map[i][j] = 0;
			else
				map[i][j] = str[idx] - 48;
		}
	}
	cout << solve(1, 1);	
}