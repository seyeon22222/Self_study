#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define INF 2147483647

int dp[100001][5][5];
vector<int> arr;
int idx;

int check(int x, int y)
{
	if (x == 0)
		return 2;
	if (x == y)
		return 1;
	if (abs(x - y) == 2)
		return 4;
	else
		return 3;
}

int memoization(int depth, int x, int y)
{
	if (depth == idx)
		return 0;
	if (dp[depth][x][y] != -1)
		return dp[depth][x][y];
	int left = memoization(depth + 1, arr[depth], y) + check(x, arr[depth]);
	int right = memoization(depth + 1, x, arr[depth]) + check(y, arr[depth]);
	return dp[depth][x][y] = min(left, right);
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1)
	{
		int num;
		cin >> num;
		if (num == 0)
			break;
		arr.push_back(num);		
	}
	memset(dp, -1, sizeof(dp));
	idx = arr.size();
	cout << memoization(0,0,0);
}
