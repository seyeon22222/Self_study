#include <iostream>
#include <vector>
using namespace std;

int n;
int res[1000006];
int ans[1000006];
vector<int>	arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
		res[temp] = 1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i] * 2; j < 1000001; j += arr[i])
		{
			if (res[j] == 1)
			{
				ans[arr[i]]++;
				ans[j]--;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[arr[i]] << " ";
}