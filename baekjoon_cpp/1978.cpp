#include <iostream>
using namespace std;

int n, ans;

bool check(int num)
{
	for (int i = 2; i * i <= num; ++i)
		if (num % i == 0)
			return false;
	return true;
}

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (check(a))
			ans++;
	}
	cout << ans;
}