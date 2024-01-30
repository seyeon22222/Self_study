#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;


int main()
{
	int n,m;
	cin >> n >> m;
	queue<int> arr;
	int visited[100001] = {0, };
	arr.push(n);
	visited[n] = 1;
	int x = 0;
	while (!arr.empty())
	{
		x = arr.front();
		arr.pop();
		if (x == m)
			break;
		if (((x * 2) >= 0 && (x * 2) < 100001) && visited[x * 2] == 0)
		{
			visited[x * 2] = visited[x] + 1;
			arr.push(x * 2);
		}
		if (((x + 1) >= 0 && (x + 1) < 100001) && visited[x + 1] == 0)
		{
			visited[x + 1] = visited[x] + 1;
			arr.push(x + 1);
		}
		if (((x - 1) >= 0 && (x - 1) < 100001) && visited[x - 1] == 0)
		{
			visited[x - 1] = visited[x] + 1;
			arr.push(x - 1);
		}
	}
	cout << visited[x] - 1;
}