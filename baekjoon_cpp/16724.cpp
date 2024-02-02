#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n,m;
char graph[1001][1001];
bool visited[1001][1001];
int parent[1001 * 1001];
set<int> arr;

int find_t(int x)
{
	if (parent[x] == x)
		return x;
	return (parent[x] = find_t(parent[x]));
}

void union_t(int x, int y)
{
	int nx = find_t(x);
	int ny = find_t(y);
	if (nx <= ny)
		parent[ny] = nx;
	else
		parent[nx] = ny;
}

void DFS(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return ;
	if (visited[x][y])
		return ;
	visited[x][y] = true;
	if (graph[x][y] == 'D')
	{
		union_t(x * m + y , (x + 1) * m + y);
		DFS(x + 1, y);
	}
	else if (graph[x][y] == 'R')
	{
		union_t(x * m + y + 1 , x * m + y);
		DFS(x, y + 1);
	}
	else if (graph[x][y] == 'L')
	{
		union_t(x * m + y - 1, x* m + y);
		DFS(x, y - 1);
	}
	else if (graph[x][y] == 'U')
	{
		union_t(x * m + y , (x - 1) * m + y);
		DFS(x - 1, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i < n * m; ++i)
		parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
			cin >> graph[i][j];
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visited[i][j])
				DFS(i,j);
			
		}
	}
	for (int i = 0; i < n * m; ++i)
		arr.insert(find_t(i));
	cout << arr.size();
}