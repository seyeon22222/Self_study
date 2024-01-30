#include <iostream>
using namespace std;

int main()
{
	int t,n,m,k;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n >> m >> k;
		int cnt = 0;
		int flag = n;
		while (n > 0)
		{
			if (cnt && flag == n)
			{
				cnt = -1;
				break ;
			}
			n = n - (m * k);
			cnt++;
			if (n <= 0)
				break ;
			n += 1;
			cnt++;
		}
		cout << cnt << endl;
	}
	
}