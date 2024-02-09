#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> arr[1001];
int inDegree[1001];
vector<int> res;
queue<int> q;

void BFS(void)
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
		for (int i = 0; i < arr[idx].size(); ++i)
		{
			int next = arr[idx][i];
			inDegree[next]--;
			if (inDegree[next] == 0)
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
		int a, prev;
		cin >> a;
		for (int j = 0; j < a; ++j)
		{
			int temp;
			cin >> temp;
			if (j != 0)
			{
				arr[prev].push_back(temp);
				inDegree[temp]++;
			}
			prev = temp;
		}
	}
	BFS();
	if (res.size() != n)
	{
		cout << "0";
		return 0;
	}
	else
	{
		for (int i = 0; i < res.size(); ++i)
			cout << res[i] << "\n";
	}
}