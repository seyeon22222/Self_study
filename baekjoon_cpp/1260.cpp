#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];
vector<int> d_tree[10001];
vector<int> d_ans;
queue<int> q_tree;
vector<int> q_ans;

void BFS()
{
	while (!q_tree.empty())
	{
		int x = q_tree.front();
		q_ans.push_back(x);
		q_tree.pop();
		for (int i = 0; i < d_tree[x].size(); i++)
		{
			int nx = d_tree[x][i];
			if (visited[nx])
				continue;
			q_tree.push(nx);
			visited[nx] = true;
		}
	}
}

void DFS(int idx)
{
	if (visited[idx])
		return;
	visited[idx] = true;
	d_ans.push_back(idx);
	for (int i = 0; i < static_cast<int>(d_tree[idx].size()); i++)
	{
		int n_idx = d_tree[idx][i];
		DFS(n_idx);
	}
}

int main()
{
	int n,m,v;
	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		d_tree[start].push_back(end);
		d_tree[end].push_back(start);
	}
	for (int i = 1; i <= n; i++)
		sort(d_tree[i].begin(), d_tree[i].end());
	DFS(v);
	for (size_t i = 0; i < d_ans.size() ; i++)
		cout << d_ans[i] << " ";
	cout << endl;
	fill(visited, visited + 1001, false);
	q_tree.push(v);
	visited[v] = true;
	BFS();
	for (size_t i = 0; i < q_ans.size() ; i++)
		cout << q_ans[i] << " ";
	cout << endl;
}