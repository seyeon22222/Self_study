#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int a,b;
	cin >> a >> b;
	queue<pair<long, int>> arr;
	arr.push({a,1});
	int res = 0;
	while (!arr.empty())
	{
		long x = arr.front().first;
		int y = arr.front().second;
		arr.pop();
		if (x == b)
		{
			res = y;
			break;
		}
		if (0 <= x * 2 && x * 2 < 1000000001)
		{
			arr.push({x * 2, y + 1});
		}
		if (0 <= ((x * 10) + 1) && ((x * 10) + 1) < 1000000001)
		{
			arr.push({(x * 10) + 1, y + 1});
		}
	}
	if (res == 0)
		res = -1;
	cout << res;
}