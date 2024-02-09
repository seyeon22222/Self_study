#include <iostream>
using namespace std;

int n;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int cnt = 0;
	int ans = 0;
	int temp = 0;
	while (cnt != n)
	{
		ans++;
		temp = ans;
		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else
				temp /= 10;
		}
	}
	cout << ans;
}