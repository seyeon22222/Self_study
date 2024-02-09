#include <iostream>
using namespace std;

int n;
int graph[129][129];
int blue, white;

void DFS(int _size, int x, int y)
{
	int color = graph[x][y];
	int div = _size / 2;
	for (int i = x; i < _size + x; ++i)
	{
		for (int j = y; j < _size + y; ++j)
		{
			if (graph[i][j] != color)
			{
				DFS(div, x, y);
				DFS(div, x, y + div);
				DFS(div, x + div, y);
				DFS(div, x + div, y + div);
				return;
			}
		}
	}
	if (color == 0)
	{
		white++;
		return ;
	}
	else
	{
		blue++;
		return ;
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> graph[i][j];
	DFS(n, 0, 0);
	cout << white << "\n" << blue;
}