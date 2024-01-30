#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[3000] = {0};

	a[0] = 13;
	a[1] = 39;
	for (int i = 2; i < n; i++)
		a[i] = a[i - 1] + (a[i - 1] - a[i - 2] + 14);
	cout << a[n-1];
}