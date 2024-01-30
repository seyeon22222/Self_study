#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,k;
int candy[30001];
int tree[30001];
int b_dp[30001];
int dp[3001];
int max_p;

int find_idx(int idx)
{
	if (idx == tree[idx])
		return idx;
	return (tree[idx] = find_idx(tree[idx]));
}

void tree_union(int x, int y)
{
	int nx = find_idx(x);
	int ny = find_idx(y);
	if (nx <= ny)
		tree[ny] = nx;
	else
		tree[nx] = ny;
}

void find_candy()
{
	for (int i = 1; i <= n; i++)
	{
		if (tree[i] != i)
		{
			int idx = find_idx(i);
			candy[idx] += candy[i];
			b_dp[idx] += b_dp[i];
		}
	}
}

int main()
{
	for (int i = 0; i < 30001; i++)
		tree[i] = i;
	fill(b_dp, b_dp + 30001, 1);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		cin >> candy[i];
	for (int i = 0; i < m; i++)
	{
		int a,b;
		cin >> a >> b;
		tree_union(a,b);
	}
	find_candy();
	for (int i = 1; i <= n; i++)
	{
		if (tree[i] != i)
			continue;
		for (int j = k - 1; j - b_dp[i] >= 0; j--)
			dp[j] = max(dp[j], dp[j - b_dp[i]] + candy[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	cout << endl;		
	cout << dp[k - 1];
}
