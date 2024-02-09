#include <iostream>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int board[110];
int visit[110];
queue<int> q;
int n, m;

void BFS()
{
	q.push(1);
	visit[1] = 0;
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i)
		{
			if (board[idx + i])
			{
				if (visit[board[idx + i]] > visit[idx] + 1) 
				{
					visit[board[idx + i]] = visit[idx] + 1;
					q.push(board[idx + i]);
				}
			}
			else if (idx + i <= 100)
			{
				if (visit[idx + i] > visit[idx] + 1) 
				{
					visit[idx + i] = visit[idx] + 1;
					q.push(idx + i);
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y;
		board[x] = y;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		board[x] = y;
	}
	fill(visit, visit + 110, INT_MAX);
	BFS();
	// for (int i = 1; i < 101; i++)
	// {
	// 	cout << visit[i] << " ";
	// 	if (i % 10 == 0)
	// 		cout << endl;
	// }
	cout << visit[100];
}