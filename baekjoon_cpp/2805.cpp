#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int h;
		cin >> h;
		v.push_back(h);
	}
	sort(v.begin(), v.end());
	int maxH = v[n - 1];
	int start = 0;
	while (start <= maxH)
	{
		int mid = (start + maxH) / 2;
		long long sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] > mid)
				sum += v[i] - mid;
		}
		if (sum >= m)
		{
			res = mid;
			start = mid + 1;
		}
		else
			maxH = mid - 1;
	}
	cout << res;
}