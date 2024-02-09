#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int n, m;
vector<int> arr[101];
queue<int> q;
int res[101];
int ans = INT_MAX;
int answer;

void bfs(int start)
{
	int temp = 0;
	fill(res, res + 101, INT_MAX);
	q.push(start);
	res[start] = 0;
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		for (int i = 0; i < arr[idx].size(); ++i)
		{
			int next = arr[idx][i];
			if (res[idx] + 1 < res[next]) {
				q.push(next);
				res[next] = res[idx] + 1;
			}
		}
	}
	for (int i = 1; i <= n; ++i)
		temp += res[i];
	if (ans > temp)
		answer = start;
	ans = min(ans,temp);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a,b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}	
	for (int i = 1; i <= n; ++i)
		bfs(i);
	cout << answer;
}