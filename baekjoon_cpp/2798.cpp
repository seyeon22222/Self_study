#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		for (int j = i + 1; j < n - 1; ++j)
			for (int k = j + 1; k < n; ++k)
			{
				int temp = arr[i] + arr[j] + arr[k];
				if (temp <= m)
					sum = max(sum, temp);
			}
	}
	cout << sum;
}