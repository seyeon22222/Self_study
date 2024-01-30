#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k;
	int cnt = 0;
	vector<int> a;
	cin >> n >> k;
	int b = 0;
	for (int i =0; i < n; i++)
	{
		cin >> b;
		a.push_back(b);
	}
	for (int i = 1; i < a.size(); i++)
	{
		if (a[i] <= a[i - 1])
		{
			a[i] += k;
			cnt++;
		}
		if (a[i] <= a[i - 1])
		{
			cnt = -1;
			break;
		}
	}
	cout << cnt << endl;
}