#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T,n;
vector<pair<int , int>> island;
vector<int> y_comp;
int tree[75001 * 4];
int cnt;

// 세그먼트 트리 구성
void TreeBuild(int idx, int start, int end)
{
	if (start > end)
		return ;
	if (start == end)
	{
		tree[idx] = 0;
		return ;
	}
	tree[idx] = 0;
	int mid = (start + end) / 2;
	TreeBuild(idx * 2, start, mid);
	TreeBuild(idx * 2 + 1, mid + 1, end);
	
}

// 구간합 찾기
int TreeQuery(int idx, int left, int right, int start, int end)
{
	if (right < start || left > end)
		return 0;
	if (left <= start && end <= right)
		return tree[idx];
	int mid = (start + end) / 2;
	int l_child = TreeQuery(idx * 2, left, right, start, mid);
	int r_child = TreeQuery(idx * 2 + 1, left, right, mid + 1, end);
	return (l_child + r_child);
}

// 세그먼트 트리 값 업데이트
void TreeUpdate(int idx, int start, int end, int target)
{
	if (target > end || target < start)
		return ;
	if (start == end)
	{
		tree[idx]++;
		return ;
	}
	int mid = (start + end) / 2;
	TreeUpdate(idx * 2, start, mid, target);
	TreeUpdate(idx * 2 + 1, mid + 1, end, target);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

bool Big(int a, int b)
{
	return a > b;
}

bool BigPair(pair<int,int> a, pair<int,int> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		cin >> n;
		// TreeBuild(1, 0, n - 1);
		fill(tree, tree + (75001 * 4), 0);
		for (int j = 0; j < n; j++)
		{
			int x,y;
			cin >> x >> y;
			island.push_back(make_pair(x,y));
			y_comp.push_back(y);
		}
		sort(island.begin(), island.end(), BigPair);
		sort(y_comp.begin(), y_comp.end(), Big);
		y_comp.erase(unique(y_comp.begin(), y_comp.end()), y_comp.end());
		long long res = 0;
		for (int k = 0; k < island.size(); ++k)
		{
			int a = island[k].first;
			int b = island[k].second;
			int idx = upper_bound(y_comp.begin(), y_comp.end(), b, Big) - y_comp.begin() - 1;
			res += TreeQuery(1, 0, idx, 0, n - 1);
			TreeUpdate(1, 0, n - 1, idx);
		}
		cout << res << "\n";
		island.clear();
		y_comp.clear();
	}
}