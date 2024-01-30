#include <iostream>
#include <climits>
using namespace std;

int m, n;
char board[51][51];
char board1[9][9] = 
{{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'},
{'B','W','B','W','B','W','B','W'},{'W','B','W','B','W','B','W','B'}};
char board2[9][9] = 
{{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'},
{'W','B','W','B','W','B','W','B'}, {'B','W','B','W','B','W','B','W'}};
int ans = INT_MAX;

void check1(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[y + i][x + j] != board1[i][j])
				cnt++;
		}
	}
	ans = min(ans, cnt);
}

void check2(int y, int x)
{
	int cnt = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (board[y + i][x + j] != board2[i][j])
				cnt++;
		}
	}
	ans = min(ans, cnt);
}

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	}
	
	for (int i = 0; i <= n - 8; ++i)
	{
		for (int j = 0; j <= m - 8; ++j)
		{
			check1(i, j);
			check2(i, j);
		}
	}
	cout << ans;
}
