#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

bool visited[100001];
int t;
int main()
{
	int n,k;
	cin >> n >> k;
	queue<pair<int, int>> arr;
	arr.push(make_pair(n, 0));
	visited[n] = true;
	int res = 0;
	while (!arr.empty())
	{
		int x = arr.front().first;
		int y = arr.front().second;
		arr.pop();
		visited[x] = 1;
		if (res && x == k && t == y)
		{
			res++;
		}
		if (!res && x == k)
		{
			t = y;
			res++;
		}
		if (((x * 2) >= 0 && (x * 2) < 100001) && visited[x * 2] == 0)
		{
			arr.push({x * 2, y + 1});
		}
		if (((x + 1) >= 0 && (x + 1) < 100001) && visited[x + 1] == 0)
		{	
			arr.push({x + 1, y + 1});
		}
		if (((x - 1) >= 0 && (x - 1) < 100001) && visited[x - 1] == 0)
		{
			arr.push({x - 1, y + 1});
		}
	}
	cout << t << endl;
	cout << res;
}