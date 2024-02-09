#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int graph[26][26];
int visit[26][26];
int cnt;
vector<int> ans;

void DFS(int x, int y, int cnt)
{
	if (x == n || y == n || x < 0 || y < 0 || !graph[x][y] || visit[x][y])
		return ;
	visit[x][y] = cnt;
	DFS(x + 1, y, cnt);
	DFS(x, y + 1, cnt);
	DFS(x - 1, y, cnt);
	DFS(x, y - 1, cnt);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	string str;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		for (int k = 0; k < str.length(); ++k)
			graph[i][k] = str[k] - '0';
	}	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (graph[i][j] && !visit[i][j])
				DFS(i, j, ++cnt);
		}
	}
	for (int a = 1; a <= cnt; ++a)
	{
		int num = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (visit[i][j] == a)
					num++;
			}
		}
		ans.push_back(num);
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); ++i)
		cout << ans[i] << "\n";
}