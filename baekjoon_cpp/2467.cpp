#include <iostream>
#include <algorithm>
using namespace std;

# define MAX 2147483647
int n;
int arr[100002];
int comp = MAX;
int res, res1;

void check(void)
{
	int start = 1;
	int end = n;
	while (start < end)
	{
		int sum = abs(arr[start] + arr[end]);
		if (sum < comp)
		{
			comp = sum;
			res = arr[start];
			res1 = arr[end];
		}
		if (arr[start] + arr[end] < 0)
			start++;
		else
			end--;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	sort(arr + 1, arr + n);
	check();	
	(res < res1) ? cout << res << " " << res1 : cout << res1 << " " << res;
}