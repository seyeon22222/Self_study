#include <iostream>
using namespace std;

#define MAX 2147483647

int n, s;
int arr[100002];
int ans = MAX;

void check(void)
{
	int start = 1;
	int end = 1;
	int sum = arr[1];

	while (start <= n && end <= n)
	{
		if (sum >= s)
		{
			ans = min(ans, end - start + 1);
			sum -= arr[start];
			start++;
		}
		else
		{
			end++;
			if (end <= n)
				sum += arr[end];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	check();
	(ans == MAX) ? cout << "0" : cout << ans;
}
