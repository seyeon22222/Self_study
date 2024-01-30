#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	char arr[6];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	int ans = 0;
	for (int i = 0; i < 5; i++)
	{
		if (arr[i] == '0')
			ans += 0;
		else if (arr[i] == '1')
			ans += 1;
		else if (arr[i] == '2')
			ans += 4;
		else if (arr[i] == '3')
			ans += 9;
		else if (arr[i] == '4')
			ans += 16;
		else if (arr[i] == '5')
			ans += 25;
		else if (arr[i] == '6')
			ans += 36;
		else if (arr[i] == '7')
			ans += 49;
		else if (arr[i] == '8')
			ans += 64;
		else if (arr[i] == '9')
			ans += 81;
	}
	cout << ans % 10;
}