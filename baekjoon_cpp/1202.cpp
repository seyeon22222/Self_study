#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
vector<pair<int , int>> jewel;
vector<pair<int , int>> bag;
long res;


void check()
{
	int idx = 0;
	priority_queue<int> pq;
	for (int i = 0; i < k; ++i)
	{
		while (idx < n && jewel[idx].first <= bag[i].first)
		{
			pq.push(jewel[idx].second);
			idx++;
		}
		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int m, v;
		cin >> m >> v;
		jewel.push_back(make_pair(m, v));
	}
	for (int i = 0; i < k; ++i)
	{
		int c;
		cin >> c;
		bag.push_back(make_pair(c, 0));
	}
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	check();
	cout << res;
}