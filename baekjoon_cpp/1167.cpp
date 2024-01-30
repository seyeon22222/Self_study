#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100001];
vector<pair<int,int>> tree[100001];
int max_res;
int max_idx;

void DFS(int idx, int value)
{
	if (visited[idx])
		return ;
	if (max_res < value)
	{
		max_res = value;
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
	int v;
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		int idx;
		cin >> idx;
		int num = 0;
		int temp = 0;
		int cnt = 0;
		while (idx != -1 && num != -1)
		{
			cin >> num;
			cnt++;
			if (cnt == 2)
			{
				tree[idx].push_back(make_pair(temp, num));
				cnt = 0;
			}
			temp = num;
		}
	}
	DFS(1, 0);
	fill(visited, visited + 100000, false);
	DFS(max_idx, 0);
	cout << max_res;
}