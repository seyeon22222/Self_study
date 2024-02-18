#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
vector<int> v[10001];
bool visited[10001];
int arr[10001];

int dfs(int x)
{
	int ret = 1;
	visited[x] = 1;
	for (int i = 0; i < v[x].size(); ++i) {
		if (visited[v[x][i]])
			continue;
		ret += dfs(v[x][i]);
	}
	return ret;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}
	int maxV = 0;
	for (int i = 1; i <= n; ++i)
	{
		memset(visited, 0, sizeof(visited));
		arr[i] = dfs(i);
		maxV = max(maxV, arr[i]);
	}

	for (int i = 1; i <= n; ++i)
	{
		if (arr[i] == maxV)
			cout << i << " ";
	}
}