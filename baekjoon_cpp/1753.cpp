#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int V,e,k,u,v,w;
int dp[20001];
vector<pair<int, int>> vec[20001];

void Dijkstra(int idx)
{
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, idx));
	dp[idx] = 0;
	while (!pq.empty())
	{
		int val = -pq.top().first;
		int e_idx = pq.top().second;
		pq.pop();
		if (val && dp[e_idx] < val)
			continue;
		for (int i = 0; i < vec[e_idx].size(); i++)
		{
			int n_val = vec[e_idx][i].first;
			int n_idx = vec[e_idx][i].second;
			if (val + n_val < dp[n_idx])
			{
				dp[n_idx] = val + n_val;
				pq.push(make_pair(-(val + n_val), n_idx));
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> V >> e;	
	cin >> k;
	fill(dp, dp + 20001, INT_MAX);
	for (int i = 0; i < e; i++)
	{
		cin >> u >> v >> w;
		vec[u].push_back(make_pair(w,v));
	}
	Dijkstra(k);
	for (int i = 1; i <= V; i++)
	{
		if (dp[i] == INT_MAX)
		{
			cout << "INF\n";
			continue;
		}
		cout << dp[i] << "\n";
	}
}