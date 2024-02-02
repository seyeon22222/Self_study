#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[100002];
int tree[100001 * 4];


void TreeBuild(int idx, int start, int end)
{
	if (start > end)
		return ;
	if (start == end)
	{
		tree[idx] = arr[start];
		return ;
	}
	tree[idx] = arr[start];
	int mid = (start + end) / 2;
	TreeBuild(idx * 2, start, mid);
	TreeBuild(idx * 2 + 1, mid + 1, end);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);	
}



int TreeQuery(int idx, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return 1000000001;
	if (left <= start && end <= right)
	{
		return tree[idx];
	}
	int mid = (start + end) / 2;
	int left_c = TreeQuery(idx * 2, start, mid, left, right);
	int right_c = TreeQuery(idx * 2 + 1, mid + 1, end, left, right);
	return (min(left_c, right_c));
}


void TreeUpdate(int idx, int start, int end, int target, int val)
{
	if (target < start || target > end)
		return ;
	if (start == end)
	{
		tree[idx] = val;
		arr[start] = val;
		return ;
	}
	int mid = (start + end) / 2;
	TreeUpdate(idx * 2, start, mid, target, val);
	TreeUpdate(idx * 2 + 1, mid + 1, end, target, val);
	tree[idx] = min(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	TreeBuild(1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int p,q,w;
		cin >> p >> q >> w;
		if (p == 1)
			TreeUpdate(1, 0, n - 1, q - 1, w);
		else
		{
			int res = TreeQuery(1, 0, n - 1, q - 1, w - 1);
			for (int i = q - 1; i <= w - 1; ++i)
			{
				if (arr[i] == res) {
					cout << i + 1 << "\n";
					break;
				}
			}
		}
	}
}