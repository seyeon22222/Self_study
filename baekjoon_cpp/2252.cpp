#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int inDegree[32001];
queue<int> q;
vector<int> v[32001];
vector<int> res;

void BFS()
{
	for (int i = 1; i <= n; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		res.push_back(idx);
		for (int i = 0; i < v[idx].size(); ++i)
		{
			int next = v[idx][i];
			inDegree[next]--;
			if (!inDegree[next])
				q.push(next);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int f, e;
		cin >> f >> e;
		v[f].push_back(e);
		inDegree[e]++;
	}
	BFS();
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
}