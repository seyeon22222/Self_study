#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[10001];
vector<pair<int,int>> tree[10001];
int max_val;
int max_idx;

void DFS(int idx, int value)
{
	if (visited[idx] == true)
		return;
	if (value > max_val)
	{
		max_val = value;
		max_idx = idx;
	}
	visited[idx] = true;
	for (int i = 0; i < static_cast<int>(tree[idx].size()); i++)
	{
		int n_idx = tree[idx][i].first;
		int n_val = tree[idx][i].second;
		DFS(n_idx, value + n_val);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int idx, start, val;
		cin >> idx >> start >> val;
		tree[idx].push_back(make_pair(start, val));
		tree[start].push_back(make_pair(idx, val));
	}
	DFS(1,0);
	fill(visited, visited + 10000, false);
	DFS(max_idx, 0);
	cout << max_val;
}