#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, a, b, c;
vector<pair<int, pair<int, int>>> vec;
long long dist[501];
vector<int> ans;

bool BellmanFord(int idx)
{
	dist[idx] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < vec.size(); ++j)
		{
			int s_idx = vec[j].first;
			int e_idx = vec[j].second.first;
			int val = vec[j].second.second;
			if (dist[s_idx] == INT_MAX)
				continue;
			if (dist[e_idx] > dist[s_idx] + val)
			{
				dist[e_idx] = dist[s_idx] + val;
				if (i == n)
					return false;
			}
			
		}
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	fill(dist, dist + 501, INT_MAX);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;		
		vec.push_back(make_pair(a, make_pair(b,c)));
	}
	if (!BellmanFord(1))
	{
		cout << "-1";
		exit(1);
	}
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] == INT_MAX)
			dist[i] = -1;
		cout << dist[i] << "\n";
	}
}