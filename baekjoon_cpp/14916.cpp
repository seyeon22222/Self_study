#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	int i;
	cin >> i;
	int dp[100001] = {0};
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	dp[4] = 2;
	dp[5] = 1;
	for (int j = 6; j <= i; j++)
	{
		if (j % 2 == 0 && j % 5 != 0)
			dp[j] = dp[j - 2] + 1;
		else if (j % 5 == 0)
			dp[j] = j / 5;
		else
			dp[j] = dp[j - 2] + 1;
	}
	cout << dp[i];
	return 0;
}