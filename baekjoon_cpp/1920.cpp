#include <iostream>
#include <algorithm>
using namespace std;

int n,m;


int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	int arr[100001];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	cin >> m;
	int find_m;
	for (int i = 0; i < m; i++)
	{
		cin >> find_m;
		if (binary_search(arr, arr + n, find_m))
			cout << "1\n";
		else
			cout << "0\n";
	}
}