#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v,e;
vector<pair<int, pair<int, int>>> tree;
int parent[10001];
int sum;

int findTree(int x)
{
	if (x == parent[x])
		return x;
	return (parent[x] = findTree(parent[x]));
}

void UnionTree(int x, int y)
{
	int nx = findTree(x);
	int ny = findTree(y);
	if (nx <= ny)
		parent[ny] = nx;
	else
		parent[nx] = ny;
}

bool check(int x, int y)
{
	int nx = findTree(x);
	int ny = findTree(y);
	if (nx == ny)
		return false;
	return true;
}

int main()
{
	cin.tie(NULL),cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> v >> e;
	for (int i = 1; i <= v; ++i)
		parent[i] = i;
	for (int i = 0; i < e; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		tree.push_back(make_pair(c, make_pair(a,b)));
	}
	sort(tree.begin(), tree.end());
	for (int i = 0; i < tree.size(); ++i)
	{
		if (check(tree[i].second.first, tree[i].second.second))
		{
			UnionTree(tree[i].second.first, tree[i].second.second);
			sum += tree[i].first;
		}
	}
	cout << sum;
}