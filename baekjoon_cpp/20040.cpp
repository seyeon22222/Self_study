#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int tree[500001];
int res;

int Treefind(int x)
{
	if (tree[x] == x)
		return x;
	return tree[x] = Treefind(tree[x]);
}

void TreeUnion(int x, int y)
{
	int nx = Treefind(x);
	int ny = Treefind(y);
	if (nx <= ny)
		tree[ny] = nx;
	else
		tree[nx] = ny;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		tree[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (Treefind(x) == Treefind(y))
		{
			res = i + 1;
			break;
		}
		TreeUnion(x, y);
	}
	cout << res;
}