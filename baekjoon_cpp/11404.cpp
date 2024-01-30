#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int n, m, a, b, c;
int arr[101][101];
int dp[101][101];

void FloydWarshall()
{
	// 무조건 거쳐가야하는 곳
	for (int i = 1; i <= n; ++i)
	{
		// 시작 지점
		for (int j = 1; j <= n; ++j)
		{
			// 도착 지점
			for (int k = 1; k <= n; ++k)
			{
				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	fill(&arr[0][0], &arr[100][100] + 1, 987654321);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		arr[a][b] = min(c, arr[a][b]);
	}
	for (int i = 1; i <= n; ++i)
		arr[i][i] = 0;
	FloydWarshall();
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (arr[i][j] == 987654321)
				arr[i][j] = 0;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}